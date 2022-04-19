
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <queue>

std::queue<int> RandomQueue(size_t n);
void EraseQueueRange(std::queue<int>& q, size_t l, size_t r);
void PrintQueue(std::queue<int> q);

#endif // _QUEUE_HPP_
