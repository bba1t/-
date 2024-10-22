#ifndef CPP2_S21_CONTAINERS_2_SRC_LIST_S21_LIST_H
#define CPP2_S21_CONTAINERS_2_SRC_LIST_S21_LIST_H

#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class list
{
    class ListConstIterator;
    class ListIterator;

    using data_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;

public:
    using iterator = ListIterator;
    using const_iterator = ListConstIterator;

    list() : size_(size_type()), head_(new Node_<T>()), tail_(head_) {}

    list(size_type n) : list()
    {
        for (size_t i = 0; i < n; i++)
            push_front(data_type());
    }

    list(const list &l) : list()
    {
        for (const auto tmp : l)
            push_back(tmp);
    }

    list(std::initializer_list<data_type> const &items) : list()
    {
        for (const auto tmp : items)
            push_back(tmp);
    }

    const_reference front() const { return head_; }
    const_reference back() const { return tail_->p_prev_; }

    bool empty() const
    {
        bool check = (head_ == nullptr) ? check = true : check = false;
        return check;
    }





    size_type size() const { return size_; }

    list &operator=(list &&l)
    {
        if (this != &l)
        {
            clear();
            std::swap(head_, l.head_);
            std::swap(tail_, l.tail_);
        }
        return *this;
    }

    list(list &&l) : list()
    {
        *this = std::move(l);
    }

    size_type max_size() const
    {
        return std::numeric_limits<size_type>::max() / 2 / sizeof(Node_<T>);
    }

    iterator insert(iterator pos, const_reference data)
    {
        Node_<T> *new_node = new Node_<T>(pos.current_, pos.current_->p_prev_, data);
        if (pos.current_ == head_)
            head_ = new_node;
        else
            pos.current_->p_prev_->p_next_ = new_node;

        pos.current_->p_prev_ = new_node;
        size_++;

        return iterator(new_node);
    }

    void push_front(const_reference data) { insert(begin(), data); }

    void push_back(const_reference data) { insert(end(), data); }

    void erase(iterator pos)
    {
        pos.current_->p_next_->p_prev_ = pos.current_->p_prev_;
        if (pos.current_ == head_)
            head_ = pos.current_->p_next_;
        else
            pos.current_->p_prev_->p_next_ = pos.current_->p_next_;

        delete pos.current_;
    }
    void pop_front() { erase(begin()); }

    void pop_back() { erase(--(end())); }

    void swap(list &other)
    {
        Node_<T> *tmp_head_ = head_;
        Node_<T> *tmp_tail_ = tail_;
        head_ = other.head_;
        tail_ = other.tail_;
        other.head_ = tmp_head_;
        other.tail_ = tmp_tail_;
    }

    void reverse()
    {
        iterator it(head_);
        for (; it.current_ != tail_; --it)
            std::swap(it.current_->p_next_, it.current_->p_prev_);

        head_->p_next_ = tail_;
        --it;
        tail_->p_prev_ = head_;
        head_ = it.current_;
    }

    void unique()
    {
        iterator it(head_);
        while (it.current_ != tail_)
        {
            data_type compared_data = it.current_->data_;
            ++it;
            while (compared_data == it.current_->data_)
            {
                iterator it_del = it++;
                erase(it_del);
            }
        }
    }

    void splice(const_iterator pos, list &other)
    {
        Node_<T> *no_const = const_cast<Node_<T> *>(pos.current_);

        if (no_const == head_)
        {
            head_ = other.head_;
        }
        else
        {
            other.head_->p_prev_ = no_const->p_prev_;
            no_const->p_prev_->p_next_ = other.head_;
        }
        other.tail_->p_prev_->p_next_ = no_const;
        no_const->p_prev_ = other.tail_->p_prev_;

        other.head_ = nullptr;
        other.tail_ = nullptr;
    }

    void sort()
    {
        Node_<T> *block_[size_]; // массив указателей на узлы из листа

        iterator it_first(head_), it_last(tail_);

        for (int i = 0; it_first.current_ != it_last.current_; ++it_first, i++)
            block_[i] = it_first.current_;

        int first = 0, last = size_ - 1;

        hoarasort(block_, first, last);
    }

    void merge(list &other)
    {
        iterator it_this = this->begin();

        while (it_this.current_->p_next_ != nullptr && other.head_->p_next_ != nullptr)
        {
            while (other.head_->p_next_ != nullptr && it_this.current_->data_ > other.head_->data_)
            {
                insert(it_this, other.head_->data_);
                other.pop_front();
            }
            if (it_this.current_->data_ <= other.head_->data_)
                ++it_this;
        }

        if (it_this.current_->p_next_ == nullptr && other.head_->p_next_ != nullptr)
            splice(iterator(end()), other);
    }
    
    iterator begin() { return iterator(head_); }
    iterator end() { return iterator(tail_); }

    const_iterator begin() const { return const_iterator(head_); }
    const_iterator end() const { return const_iterator(tail_); }



    void clear()
    {
        while (head_ != tail_)
            erase(begin());
    }

    ~list()
    {
        clear();
        delete tail_;
    }

private:
    class Node_<T>
    {
    public:
        Node_<T>() : p_next_(nullptr), p_prev_(nullptr), data_(data_type()) {}
        Node_<T>(Node_<T> *next, Node_<T> *prev, const_reference data) : p_next_(next), p_prev_(prev), data_(data) {}

        Node_<T> *p_next_;
        Node_<T> *p_prev_;
        data_type data_;
    };

    class ListIterator
    {
        friend list;

    public:
        reference operator*() { return current_->data_; }

        iterator &operator++()
        {
            this->current_ = this->current_->p_next_;
            return *this;
        }
        
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator &operator--()
        {
            this->current_ = this->current_->p_prev_;
            return *this;
        }

        iterator operator--(int)
        {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(const iterator &other)
        {
            return this->current_ == other.current_;
        }

        bool operator!=(const iterator &other)
        {
            return this->current_ != other.current_;
        }

    private:
        ListIterator(Node_<T> *node) : current_(node) {}
        ListIterator(const_iterator &other) : current_(other.current_) {}
        Node_<T> *current_;
    };

    class ListConstIterator
    {
        friend list;
    public:
        ListConstIterator(const ListIterator &other)
        {
            current_ = other.current_;
        }

        const_reference operator*() const { return current_->data_; }

        const_iterator &operator++()
        {
            this->current_ = this->current_->p_next_;
            return *this;
        }
        
        const_iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const_iterator &operator--()
        {
            this->current_ = this->current_->p_prev_;
            return *this;
        }

        const_iterator operator--(int)
        {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        friend bool operator==(const_iterator &it1, const_iterator &it2)
        {
            return it1.current_ == it2.current_;
        }

        friend bool operator!=(const_iterator &it1, const_iterator &it2)
        {
            return it1.current_ != it2.current_;
        }

    private:
        const Node_<T> *current_;
    };

    size_type size_;
    Node_<T> *head_;
    Node_<T> *tail_;

    void hoarasort(Node_<T> **block_, int first, int last)
    {
        data_type tmp, x = block_[(first + last) / 2]->data_;
        int i = first, j = last;
        do
        {
            while (block_[i]->data_ < x)
                i++;
            while (block_[j]->data_ > x)
                j--;

            if (i <= j)
            {
                if (i < j)
                {
                    tmp = block_[i]->data_;
                    block_[i]->data_ = block_[j]->data_;
                    block_[j]->data_ = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j); // от сюда получаем новый j который равен концу нового массива
                          // и новый i который равен началу второго нового массива
        if (i < last)
            hoarasort(block_, i, last);

        if (first < j)
            hoarasort(block_, first, j);

        // отсортировать сначала левую сторону потом правую
    }
};

} //namespace 21
#endif  // // CPP2_S21_CONTAINERS_2_SRC_QUEUE_S21_QUEUE_H
