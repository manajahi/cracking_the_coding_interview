/* iterator_traits.hh
 * Defines traits for LinkedList iterators
 * 
 * Copyright 2016 Edmund Highan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DATA_STRUCTS_LINKEDLISTS_TRAITS_ITERATOR_HH
#define DATA_STRUCTS_LINKEDLISTS_TRAITS_ITERATOR_HH

#ifdef DATA_STRUCTS_LINKEDLISTS_ITERATOR_HH

#include <iterator>

namespace datastructs
{
    namespace linkedlists
    {
        enum class iterator_tag
        {
            forward_iterator_tag,
            bidirectional_iterator_tag
        };        

        enum class direction {forward, reverse};

        template<direction D>
        struct direction_selector
        {
            template<typename N>
            static N * moveToNext(N * node)
            {
                return node->_next;
            }

            template<typename N>
            static N * moveToPrevious(N * node)
            {
                return node->_previous;
            } 
        };

        template<>
        struct direction_selector<direction::reverse>
        {
            template<typename N>
            static N * moveToNext(N * node)
            {
                return node->_previous;
            }

            template<typename N>
            static N * moveToPrevious(N * node)
            {
                return node->_next;
            }
        };

        template<typename N, direction D>
        N * moveToNext(N * node)
        {
            return direction_selector<D>::moveToNext(node);
        }

        template<typename N, direction D>
        N * moveToPrevious(N * node)
        {                                                             
            return direction_selector<D>::moveToPrevious(node);
        }
    } // !linkedlists
} // !datastructs

#endif // DATA_STRUCTS_LINKEDLISTS_ITERATOR_HH
#endif // DATA_STRUCTS_LINKEDLISTS_ITERATOR_TRAITS_HH
