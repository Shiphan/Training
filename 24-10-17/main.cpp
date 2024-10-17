#include <cstddef>
#include <stdexcept>
template <class T>
class Queue {
private:
	const size_t size;
	T* datas;
	size_t head;
	size_t len;
public:
	Queue(size_t size) : size(size) {
		this->datas = new T[size];
		this->head = 0;
		this->len = 0;
	}
	~Queue() {
		delete[] this->datas;
	}
	void in(const T& data) {
		if (this->len == this->size) {
			throw std::runtime_error("the queue is full");
		}
		this->datas[(head + len) % this->size] = data;
		this->len++;
	}
	T out() {
		if (this->len == 0) {
			throw std::runtime_error("the stack is empty");
		}
		T result = this->datas[head];
		this->head = (this->head + 1) % this->size; 
		this->len--;
		return result;
	}
};
