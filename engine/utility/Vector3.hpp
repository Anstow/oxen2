#ifndef OXENGINE_VECTOR3_HPP
#define OXENGINE_VECTOR3_HPP

namespace oxEngine {

template <typename T>
struct Vector3 {
    T x, y, z;

    template <typename S>
    auto dot(const Vector3<S>& rhs) const
        -> decltype(x * rhs.x + y * rhs.y + z * rhs.z)
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    template <typename S>
    auto cross(const Vector3<S>& rhs) const
        -> Vector3<decltype(y * rhs.z - z * rhs.y)>
    {
        return {
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x };
    }

    T magnitudeSquared() const {
        return x*x + y*y + z*z;
    }

    /*
    T magnitude() const {
        return std::sqrt(magnitudeSquared());
    }

    Vector3 unit() const {
        T mag = magnitude();
        return { x / mag, y / mag, z / mag };
    }
    */

    template <typename S>
    Vector3& operator+=(const Vector3<S>& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        
        return *this;
    }

    template <typename S>
    Vector3& operator+=(const S& rhs) {
        x += rhs;
        y += rhs;
        z += rhs;
        
        return *this;
    }

    template <typename S>
    Vector3& operator-=(const Vector3<S>& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        
        return *this;
    }

    template <typename S>
    Vector3& operator-=(const S& rhs) {
        x -= rhs;
        y -= rhs;
        z -= rhs;
        
        return *this;
    }

    template <typename S>
    Vector3& operator*=(const Vector3<S>& rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        
        return *this;
    }

    template <typename S>
    Vector3& operator*=(const S& rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        
        return *this;
    }

    template <typename S>
    Vector3& operator/=(const Vector3<S>& rhs) {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        
        return *this;
    }

    template <typename S>
    Vector3& operator/=(const S& rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        
        return *this;
    }
};

template <typename S, typename T>
inline auto operator+(const Vector3<S>& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs.x + rhs.x)>
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

template <typename S, typename T>
inline auto operator+(const Vector3<S>& lhs, const T& rhs)
    -> Vector3<decltype(lhs.x + rhs)>
{
    return { lhs.x + rhs, lhs.y + rhs, lhs.z + rhs };
}

template <typename S, typename T>
inline auto operator+(const S& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs + rhs.x)>
{
    return { lhs + rhs.x, lhs + rhs.y, lhs + rhs.z };
}

template <typename S, typename T>
inline auto operator-(const Vector3<S>& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs.x - rhs.x)>
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

template <typename S, typename T>
inline auto operator-(const Vector3<S>& lhs, const T& rhs)
    -> Vector3<decltype(lhs.x - rhs)>
{
    return { lhs.x - rhs, lhs.y - rhs, lhs.z - rhs };
}

template <typename S, typename T>
inline auto operator-(const S& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs - rhs.x)>
{
    return { lhs - rhs.x, lhs - rhs.y, lhs - rhs.z };
}

template <typename S, typename T>
inline auto operator*(const Vector3<S>& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs.x * rhs.x)>
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

template <typename S, typename T>
inline auto operator*(const Vector3<S>& lhs, const T& rhs)
    -> Vector3<decltype(lhs.x * rhs)>
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

template <typename S, typename T>
inline auto operator*(const S& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs * rhs.x)>
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}

template <typename S, typename T>
inline auto operator/(const Vector3<S>& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs.x / rhs.x)>
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
}

template <typename S, typename T>
inline auto operator/(const Vector3<S>& lhs, const T& rhs)
    -> Vector3<decltype(lhs.x / rhs)>
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

template <typename S, typename T>
inline auto operator/(const S& lhs, const Vector3<T>& rhs)
    -> Vector3<decltype(lhs / rhs.x)>
{
    return { lhs / rhs.x, lhs / rhs.y, lhs / rhs.z };
}

using Vector3i = Vector3<int>;
using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;

} // namespace oxEngine

#endif // OXENGINE_VECTOR3_HPP
