template<typename _t> class linq {
public:
    linq(std::vector<_t>& _arr) {
        typename std::vector<_t>::iterator end = _arr.end();
        _vec.reserve(_arr.capacity());
        for (typename std::vector<_t>::iterator begin = _arr.begin(); begin != end; ++begin) {
            _vec.push_back(*begin);
        }
    }
    // âîçâðàùàåò âåêòîð
    std::vector<_t> tovector() { 
        return _vec;
    }
    // âîçâðàùàåò ìàññèâ
    _t* toarray() {
        _t* retarray = new _t[_vec.size()];
        std::copy(_vec._Unchecked_begin(), _vec._Unchecked_end(), retarray);
        return retarray;
    }
    // âûáîðêà ýëåìåíòîâ - ïðåäèêàò ñ àðãóìåíòîì ïî ññûëêå
    linq<_t>* where(bool(*func)(_t& type)) {
        for (typename std::vector<_t>::iterator begin = _vec.begin(); begin != _vec.end();) {
            if (!func(*begin)) {
                begin = _vec.erase(begin);
            }
            else {
                ++begin;
            }
        }
        return this;
    }
    // âûáîðêà ýëåìåíòîâ
    linq<_t>* where(bool(*func)(_t type)) {
        for (typename std::vector<_t>::iterator begin = _vec.begin(); begin != _vec.end();) {
            if (!func(*begin)) {
                begin = _vec.erase(begin);
            }
            else {
                ++begin;
            }
        }
        return this;
    }
    typename std::vector<_t>::iterator min_element() {
        if (_vec.size() == 1) { return _vec.begin(); }
        typename std::vector<_t>::iterator begin = ++(_vec.begin());
        typename std::vector<_t>::iterator end = _vec.end();
        typename std::vector<_t>::iterator minelem = begin;
        for (; begin < _vec.end(); ++begin) {
            if (*minelem > *begin) {
                minelem = begin;
            }
           return minelem;
        }
    }
    typename std::vector<_t>::iterator max_element() {
        if (_vec.size() == 1) { return _vec.begin(); }
        typename std::vector<_t>::iterator begin = ++(_vec.begin());
        typename std::vector<_t>::iterator end = _vec.end();
        typename std::vector<_t>::iterator maxelem = begin;
        for (; begin < _vec.end(); ++begin) {
            if (*maxelem < *begin) {
                maxelem = begin;
            }
        }
        return maxelem;
    }
    linq<_t>* orderby() {
        std::sort(_vec.begin(), _vec.end(), [](_t a, _t b) {return a < b; });
        return this;
    }
    linq<_t>* orderbydescending() {
        std::sort(_vec.begin(), _vec.end(), [](_t a, _t b) {return a > b; });
        return this;
    }
    template<typename type> linq<_t>* apply(_t(*func)(type& t)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            *first = func(*first);
        }
        return this;
    }
    template<typename type> linq<_t>* apply(_t(*func)(type t)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            *first = func(*first);
        }
        return this;
    }
    linq<_t>* apply(void(*func)(_t& t)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            func(*first);
        }
        return this;
    }
    linq<_t>* reverse() {
        for (typename std::vector<_t>::iterator first = _vec.begin(),
            last = --_vec.end();
            first < last;
            ++first, --last) {
            std::swap(*first, *last);
        }
        return this;
    }
    size_t sum() {
        size_t _sum = 0;
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            _sum += *first;
        }
        return _sum;
    }
    //âûáîðêà ïî ëÿìáäå - àðãóìåíò ïî ññûëêå
    size_t count(bool(*f)(_t& arg)) {
        size_t _c = 0;
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            if (f(*first)) {
                ++_c;
            }
        }
        return _c;
    }
    //âûáîðêà ïî ëÿìáäå - àðãóìåíò íå ïî ññûëêå
    size_t count(bool(*f)(_t arg)) {
        size_t _c = 0;
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            if (f(*first)) {
                ++_c;
            }
        }
        return _c;
    }
    size_t count(_t &value) {
        size_t _c = 0;
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            if (value == *first) {
                ++_c;
            }
        }
        return _c;
    }
    size_t count(_t value) {
        size_t _c = 0;
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != last; ++first) {
            if (value == *first) {
                ++_c;
            }
        }
        return _c;
    }
    size_t count() {
        return _vec.size();
    }
    bool any(bool(*func)(_t& type)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != _vec.end(); ++first) {
            if (func(*first)) {
                return 1;
            }
        }
        return 0;
    }
    bool any(bool(*func)(_t type)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != _vec.end(); ++first) {
            if (func(*first)) {
                return 1;
            }
        }
        return 0;
    }
    bool all(bool(*func)(_t& type)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != _vec.end(); ++first) {
            if (!func(*first)) {
                return 0;
            }
        }
        return 1;
    }
    bool all(bool(*func)(_t type)) {
        typename std::vector<_t>::iterator last = _vec.end();
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != _vec.end(); ++first) {
            if (!func(*first)) {
                return 0;
            }
        }
        return 1;
    }
    template<typename __t> std::vector<__t> select(__t(*func)(_t&)) {
        typename std::vector<_t>::iterator last = _vec.end();
        std::vector<__t> retvec;
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != _vec.end(); ++first) {
            retvec.push_back(func(*first));
        }
        return retvec;
    }
    template<typename __t> std::vector<__t> select(__t(*func)(_t)) {
        typename std::vector<_t>::iterator last = _vec.end();
        std::vector<__t> retvec;
        for (typename std::vector<_t>::iterator first = _vec.begin(); first != _vec.end(); ++first) {
            retvec.push_back(func(*first));
        }
        return retvec;
    }
private:
    std::vector<_t> _vec;
};
template<typename t> linq<t>* from(std::vector<t> arr) {
    return new linq<t>(arr);
}

