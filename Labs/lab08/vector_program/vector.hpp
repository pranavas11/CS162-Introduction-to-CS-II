#include <stdlib.h>

template <class T>
class vector {
  private:
		// template vector (note: the type is not specified so that this could be int, float, string, etc.)
    T *v;
    int s;					// size of array
		int capacity;

  public:
    vector() {
      s = 0;
      v = NULL;
    }

		vector(int arr_capacity) {
			s = 0;
			capacity = arr_capacity;
			v = new T[capacity];
			for (int i = 0; i < capacity; i++) v[i] = 0;
		}

		vector(vector<T> &other) {
			s = other.s;
			//v = other.v;
			T* temp = new T[s];
			for (int i = 0; i < s; i++) temp[i] = other.v[i];
			v = temp;
		}

		void operator=(vector<T> &other) {
			if (s != 0) delete [] v;
			s = other.s;
			T* temp = new T[s];
			for (int i = 0; i < s; i++) {
				temp[i] = other.v[i];
			}
			v = temp;
			//return *this;
		}

		void resize(int new_size) {
			T* temp = new T[new_size];
			if(new_size < s) {
        for (int i = 0; i < new_size; i++) temp[i] = v[i];
        delete v;
        v = temp;
        return;
      }
      for (int i = 0; i < new_size; i++) {
        if (i <= s - 1) temp[i] = v[i];
        else temp[i] = 0;
      }
      delete v;
      v = temp;
		}

    int size() { return s; }

		T& operator[](int num) {
			return v[num];		// only performs address arithmetic
		}

		T& at(int num) {			// check to make sure not out of bounds
			if (s == 0) throw 0;
			if(num < 0 || num > s - 1) throw 0;
			return v[num];
			/*try {
				if (s == 0) throw 0;
				if(num < 0 || num > s - 1) throw 0;
				return v[num];
			} catch (...int e) {
				cout << "Error: number out of bounds!\n";
			}*/
		}

    void push_back(T ele) {
      T *temp;
      temp = new T[++s];
			if(s > capacity) capacity = s;
      for(int i = 0; i < s-1; i++) temp[i]=v[i];
      delete [] v;
      v = temp;
      v[s-1] = ele;
    }

		~vector() { delete [] v; }
};