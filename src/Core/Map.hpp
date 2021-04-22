//
// Created by PinkySmile on 22/04/2021.
//

#ifndef SWRSTOYS_MAP_HPP
#define SWRSTOYS_MAP_HPP


#include <vector>

namespace SokuLib
{
	template<typename T, typename T2>
	struct MapNode {
		MapNode<T, T2> *prev;
		MapNode<T, T2> *next;
		MapNode<T, T2> *head;
		std::pair<T, T2> data;
	};

	template<typename T, typename T2>
	struct Map {
	private:
		static void _exploreList(MapNode<T, T2> *chain, std::vector<MapNode<T, T2> *> &lookup)
		{
			if (std::find(lookup.begin(), lookup.end(), chain) != lookup.end())
				return;
			lookup.push_back(chain);
			Map<T, T2>::_exploreList(chain->next, lookup);
			Map<T, T2>::_exploreList(chain->prev, lookup);
			Map<T, T2>::_exploreList(chain->head, lookup);
		}

	public:
		char offset_0x00[4];
		MapNode<T, T2> *data;
		unsigned int someKindOfSize;

		std::vector<std::pair<T, T2> *> vector()
		{
			std::vector<MapNode<T, T2> *> chains{
				reinterpret_cast<MapNode<T, T2> *>(this),
				this->data
			};
			std::vector<std::pair<T, T2> *> result;

			Map<T, T2>::_exploreList(this->data->next, chains);
			Map<T, T2>::_exploreList(this->data->prev, chains);
			Map<T, T2>::_exploreList(this->data->head, chains);
			chains.erase(chains.begin(), chains.begin() + 2);
			for (auto chain : chains)
				result.push_back(&chain->data);
			return result;
		}

		T2 &operator[](const T &key);
	};

	template<>
	unsigned char &Map<unsigned short, unsigned char>::operator[](const unsigned short &key);
}

#endif //SWRSTOYS_MAP_HPP
