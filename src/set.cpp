#include "project/set.h"

#include <algorithm>
#include <stdexcept>

Set::Set() = default;

bool Set::empty() const noexcept {
    return elements_.empty();
}

std::size_t Set::size() const noexcept {
    return elements_.size();
}

bool Set::contains(int value) const {
    return containsInternal(value);
}

bool Set::insert(int value) {
    if (containsInternal(value)) {
        return false;
    }
    elements_.push_back(value);
    return true;
}

bool Set::erase(int value) {
    auto it = std::find(elements_.begin(), elements_.end(), value);
    if (it == elements_.end()) {
        return false;
    }
    elements_.erase(it);
    return true;
}

void Set::clear() {
    elements_.clear();
}

std::vector<int> Set::toVector() const {
    std::vector<int> result = elements_;
    std::sort(result.begin(), result.end());
    return result;
}

bool Set::isSubsetOf(const Set& other) const {
    for (int value : elements_) {
        if (!other.containsInternal(value)) {
            return false;
        }
    }
    return true;
}

bool Set::equals(const Set& other) const {
    return size() == other.size() && isSubsetOf(other);
}

Set Set::unionWith(const Set& other) const {
    Set result = *this;
    for (int value : other.elements_) {
        result.insert(value);
    }
    return result;
}

Set Set::intersectionWith(const Set& other) const {
    Set result;
    for (int value : elements_) {
        if (other.containsInternal(value)) {
            result.insert(value);
        }
    }
    return result;
}

Set Set::difference(const Set& other) const {
    Set result = *this;
    for (int value : other.elements_) {
        result.erase(value);
    }
    return result;
}

bool Set::containsInternal(int value) const {
    return std::find(elements_.begin(), elements_.end(), value) != elements_.end();
}
