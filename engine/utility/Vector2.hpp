#ifndef OXENGINE_VECTOR2_HPP
#define OXENGINE_VECTOR2_HPP

namespace oxEngine {

template <typename T>
struct Vector2 {
    T x, y;

    template <typename S>
    auto dot(const Vector2<S>& rhs) const
        -> decltype(x * rhs.x + y * rhs.y)
    {
        return x * rhs.x + y * rhs.y;
    }

    T magnitudeSquared() const {
        return x*x + y*y;
    }

    /*
    T magnitude() const {
        return std::sqrt(magnitudeSquared());
    }

    Vector2 unit() const {
        T mag = magnitude();
        return { x / mag, y / mag };
    }
    */

    template <typename S>
    Vector2& operator+=(const Vector2<S>& rhs) {
        x += rhs.x;
        y += rhs.y;
        
        return *this;
    }

    template <typename S>
    Vector2& operator+=(const S& rhs) {
        x += rhs;
        y += rhs;
        
        return *this;
    }

    template <typename S>
    Vector2& operator-=(const Vector2<S>& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        
        return *this;
    }

    template <typename S>
    Vector2& operator-=(const S& rhs) {
        x -= rhs;
        y -= rhs;
        
        return *this;
    }

    template <typename S>
    Vector2& operator*=(const Vector2<S>& rhs) {
        x *= rhs.x;
        y *= rhs.y;
        
        return *this;
    }

    template <typename S>
    Vector2& operator*=(const S& rhs) {
        x *= rhs;
        y *= rhs;
        
        return *this;
    }

    template <typename S>
    Vector2& operator/=(const Vector2<S>& rhs) {
        x /= rhs.x;
        y /= rhs.y;
        
        return *this;
    }

    template <typename S>
    Vector2& operator/=(const S& rhs) {
        x /= rhs;
        y /= rhs;
        
        return *this;
    }
};

template <typename S, typename T>
inline auto operator+(const Vector2<S>& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs.x + rhs.x)>
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

template <typename S, typename T>
inline auto operator+(const Vector2<S>& lhs, const T& rhs)
    -> Vector2<decltype(lhs.x + rhs)>
{
    return { lhs.x + rhs, lhs.y + rhs };
}

template <typename S, typename T>
inline auto operator+(const S& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs + rhs.x)>
{
    return { lhs + rhs.x, lhs + rhs.y };
}

template <typename S, typename T>
inline auto operator-(const Vector2<S>& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs.x - rhs.x)>
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

template <typename S, typename T>
inline auto operator-(const Vector2<S>& lhs, const T& rhs)
    -> Vector2<decltype(lhs.x - rhs)>
{
    return { lhs.x - rhs, lhs.y - rhs };
}

template <typename S, typename T>
inline auto operator-(const S& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs - rhs.x)>
{
    return { lhs - rhs.x, lhs - rhs.y };
}

template <typename S, typename T>
inline auto operator*(const Vector2<S>& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs.x * rhs.x)>
{
    return { lhs.x * rhs.x, lhs.y * rhs.y };
}

template <typename S, typename T>
inline auto operator*(const Vector2<S>& lhs, const T& rhs)
    -> Vector2<decltype(lhs.x * rhs)>
{
    return { lhs.x * rhs, lhs.y * rhs };
}

template <typename S, typename T>
inline auto operator*(const S& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs * rhs.x)>
{
    return { lhs * rhs.x, lhs * rhs.y };
}

template <typename S, typename T>
inline auto operator/(const Vector2<S>& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs.x / rhs.x)>
{
    return { lhs.x / rhs.x, lhs.y / rhs.y };
}

template <typename S, typename T>
inline auto operator/(const Vector2<S>& lhs, const T& rhs)
    -> Vector2<decltype(lhs.x / rhs)>
{
    return { lhs.x / rhs, lhs.y / rhs };
}

template <typename S, typename T>
inline auto operator/(const S& lhs, const Vector2<T>& rhs)
    -> Vector2<decltype(lhs / rhs.x)>
{
    return { lhs / rhs.x, lhs / rhs.y };
}

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

} // namespace oxEngine

#endif // OXENGINE_VECTOR2_HPP
