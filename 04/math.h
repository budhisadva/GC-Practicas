#include <iostream>
#include <cmath>
using namespace std;
/**
 * @class Vector3
 * @brief La clase Vector3 representa vectores de tres componentes (x, y, z).
 */
class Vector3 {
public:
    /**
     * @brief Constructor por defecto.
     * @param x Componente x del vector. Valor por defecto es 0.0.
     * @param y Componente y del vector. Valor por defecto es 0.0.
     * @param z Componente z del vector. Valor por defecto es 0.0.
     */
    Vector3(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}
    /**
     * Métodos getter
     */
    double getX() const {return this->x;}
    double getY() const {return this->y;}
    double getZ() const {return this->z;}
    /**
     * @brief Suma de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector resultante de la suma.
     */
    static Vector3 add(const Vector3& u, const Vector3& v) {
      return Vector3(u.x+v.x, u.y+v.y, u.z+v.z);
    }
    /**
     * @brief Sobrecarga del operador += para sumar otro vector a este vector.
     * @param v El vector a sumar.
     * @return Referencia al vector resultante después de la suma.
     */
    Vector3& operator+=(const Vector3& v) {
      this->x += v.x;
      this->y += v.y;
      this->z += v.z;
      return *this;
    }
    /**
     * @brief Clona el vector actual.
     * @return Copia del vector actual.
     */
    Vector3 clone() const {
      return Vector3(this->x, this->y, this->z);
    }
    /**
     * @brief Producto cruz de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector resultante del producto cruz.
     */
    static Vector3 cross(const Vector3& u, const Vector3& v) {
      return Vector3((u.y*v.z) - (u.z*v.y),
                     (u.z*v.x) - (u.x*v.z),
                     (u.x*v.y) - (u.y*v.x));
    }
    /**
     * @brief Distancia euclidiana entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Distancia euclidiana entre los vectores.
     */
    static double distance(const Vector3& u, const Vector3& v) {
      return sqrt(pow(u.x-v.x,2) + pow(u.y-v.y,2) + pow(u.z-v.z,2));
    }
    /**
     * @brief Producto punto de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Producto punto de los vectores.
     */
    static double dot(const Vector3& u, const Vector3& v) {
      return (u.x*v.x) + (u.y*v.y) + (u.z*v.z);
    }
    /**
     * @brief Comprueba si dos vectores son aproximadamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @param epsilon Tolerancia para la comparación. Valor por defecto es 0.000001.
     * @return Verdadero si los vectores son aproximadamente iguales.
     */
    static bool equals(const Vector3& u, const Vector3& v, double epsilon = 0.000001) {
      return (fabs(u.x-v.x) <= epsilon) && (fabs(u.y-v.y) <= epsilon) && (fabs(u.z-v.z) <= epsilon);
    }
    /**
     * @brief Comprueba si dos vectores son exactamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Verdadero si los vectores son exactamente iguales.
     */
    static bool exactEquals(const Vector3& u, const Vector3& v) {
      return (u.x == v.x) && (u.y == v.y) && (u.z == v.z);
    }
    /**
     * @brief Normaliza el vector actual.
     * @return Vector normalizado.
     */
    Vector3 normalize() const {
      double l = sqrt(pow(this->x,2) + pow(this->y,2) + pow(this->z,2));
      if (l == 0) {
        return Vector3();
      }
      return Vector3(this->x/l, this->y/l, this->z/l);
    }
    /**
     * @brief Asigna nuevos valores al vector.
     * @param x Componente x del vector. Valor por defecto es 0.0.
     * @param y Componente y del vector. Valor por defecto es 0.0.
     * @param z Componente z del vector. Valor por defecto es 0.0.
     */
    void set(double x = 0.0, double y = 0.0, double z = 0.0) {
      this->x = x;
      this->y = y;
      this->z = z;
    }
    /**
     * @brief Resta dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector resultante de la resta.
     */
    static Vector3 subtract(const Vector3& u, const Vector3& v) {
      return Vector3(u.x-v.x, u.y-v.y, u.z-v.z);
    }
    /**
     * @brief Distancia euclidiana al cuadrado entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Distancia euclidiana al cuadrado entre los vectores.
     */
    static double squaredDistance(const Vector3& u, const Vector3& v) {
      return pow(Vector3::distance(u, v),2);
    }
    /**
     * @brief Asigna el vector a cero.
     */
    void zero() {
      this->set();
    }
private:
    double x, y, z;
};
/**
 * @class Vector4
 * @brief La clase Vector4 representa vectores de tres componentes (x, y, z, w).
 */
class Vector4 {
public:
    double x, y, z, w;
    /**
     * @brief Constructor que inicializa los componentes del vector.
     * @param x Componente x del vector (por defecto 0).
     * @param y Componente y del vector (por defecto 0).
     * @param z Componente z del vector (por defecto 0).
     * @param w Componente w del vector (por defecto 0).
     */
    Vector4(double x = 0, double y = 0, double z = 0, double w = 0) : x(x), y(y), z(z), w(w) {}
    /**
     * Métodos getter
     */
    double getX() const {return this->x;}
    double getY() const {return this->y;}
    double getZ() const {return this->z;}
    double getW() const {return this->w;}
    /**
     * @brief Devuelve la suma de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector4 Resultado de la suma de u y v.
     */
    static Vector4 add(const Vector4& u, const Vector4& v) {
      return Vector4(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
    }
    /**
     * @brief Devuelve una copia del objeto Vector4.
     * @return Vector4 Copia del objeto actual.
     */
    Vector4 clone() const {
      return Vector4(this->x, this->y, this->z, this->w);
    }
    /**
     * @brief Devuelve la distancia euclidiana entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return double Distancia euclidiana entre u y v.
     */
    static double distance(const Vector4& u, const Vector4& v) {
      return sqrt(pow(u.x-v.x,2) + pow(u.y-v.y,2) + pow(u.z-v.z,2) + pow(u.w-v.w,2));
    }
    /**
     * @brief Devuelve el producto punto de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return double Producto punto de u y v.
     */
    static double dot(const Vector4& u, const Vector4& v) {
      return (u.x*v.x) + (u.y*v.y) + (u.z*v.z) + (u.w*v.w);
    }
    /**
     * @brief Verifica si dos vectores son aproximadamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @param epsilon Tolerancia para la comparación (por defecto 0.000001).
     * @return bool True si los vectores son aproximadamente iguales, false en caso contrario.
     */
    static bool equals(const Vector4& u, const Vector4& v, double epsilon = 0.000001) {
      return (fabs(u.x-v.x) <= epsilon) && (fabs(u.y-v.y) <= epsilon) && (fabs(u.z-v.z) <= epsilon) && (fabs(u.w-v.w) <= epsilon);
    }
    /**
     * @brief Verifica si dos vectores son exactamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return bool True si los vectores son exactamente iguales, false en caso contrario.
     */
    static bool exactEquals(const Vector4& u, const Vector4& v) {
      return (u.x == v.x) && (u.y == v.y) && (u.z == v.z) && (u.w == v.w);
    }
    /**
     * @brief Devuelve el vector normalizado.
     * @return Vector4 Vector normalizado.
     */
    Vector4 normalize() const {
      double l = sqrt(pow(this->x,2) + pow(this->y,2) + pow(this->z,2) + pow(this->w,2));
      if (l == 0) {
        return Vector4();
      }
      return Vector4(this->x/l, this->y/l, this->z/l, this->w/l);
    }
    /**
     * @brief Asigna nuevos valores a los componentes del vector.
     * @param x Nuevo valor para el componente x.
     * @param y Nuevo valor para el componente y.
     * @param z Nuevo valor para el componente z.
     * @param w Nuevo valor para el componente w.
     */
    void set(double x, double y, double z, double w) {
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = w;
    }
    /**
     * @brief Devuelve la resta de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector4 Resultado de la resta de u y v.
     */
    static Vector4 subtract(const Vector4& u, const Vector4& v) {
      return Vector4(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
    }
    /**
     * @brief Devuelve la distancia euclidiana al cuadrado entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return double Distancia euclidiana al cuadrado entre u y v.
     */
    static double squaredDistance(const Vector4& u, const Vector4& v) {
      return pow(Vector4::distance(u, v),2);
    }
    /**
     * @brief Asigna cero a cada componente del vector.
     */
    void zero() {
      this->set(0,0,0,0);
    }
};
/**
 * @class Matrix3
 * @brief La clase Matrix3 representa matrices de 3 × 3 y se utiliza para la representación y construcción de transformaciones en dos dimensiones.
 */
class Matrix3 {
public:
    double a00, a01, a02;
    double a10, a11, a12;
    double a20, a21, a22;
    /**
     * @brief Constructor por defecto.
     * @param a00 Elemento en la posición (0,0). Valor por defecto es 1.
     * @param a01 Elemento en la posición (0,1). Valor por defecto es 0.
     * @param a02 Elemento en la posición (0,2). Valor por defecto es 0.
     * @param a10 Elemento en la posición (1,0). Valor por defecto es 0.
     * @param a11 Elemento en la posición (1,1). Valor por defecto es 1.
     * @param a12 Elemento en la posición (1,2). Valor por defecto es 0.
     * @param a20 Elemento en la posición (2,0). Valor por defecto es 0.
     * @param a21 Elemento en la posición (2,1). Valor por defecto es 0.
     * @param a22 Elemento en la posición (2,2). Valor por defecto es 1.
     */
    Matrix3(double a00 = 1, double a01 = 0, double a02 = 0,
            double a10 = 0, double a11 = 1, double a12 = 0,
            double a20 = 0, double a21 = 0, double a22 = 1) {
              this->a00 = a00; this->a01 = a01; this->a02 = a02;
              this->a10 = a10; this->a11 = a11; this->a12 = a12;
              this->a20 = a20; this->a21 = a21; this->a22 = a22;
    }
    /**
     * @brief Suma de dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matriz resultante de la suma.
     */
    static Matrix3 add(const Matrix3& m1, const Matrix3& m2) {
      return Matrix3(
        m1.a00+m2.a00, m1.a01+m2.a01, m1.a02+m2.a02,
        m1.a10+m2.a10, m1.a11+m2.a11, m1.a12+m2.a12,
        m1.a20+m2.a20, m1.a21+m2.a21, m1.a22+m2.a22
      );
    }
    /**
     * @brief Calcula la matriz adjoint.
     * @return Matriz adjoint.
     */
    Matrix3 adjoint() const {
      double det_m00 = (this->a11*this->a22)-(this->a12*this->a21);
      double det_m01 = (this->a10*this->a22)-(this->a12*this->a20);
      double det_m02 = (this->a10*this->a21)-(this->a11*this->a20);
      double det_m10 = (this->a01*this->a22)-(this->a02*this->a21);
      double det_m11 = (this->a00*this->a22)-(this->a02*this->a20);
      double det_m12 = (this->a00*this->a21)-(this->a01*this->a20);
      double det_m20 = (this->a01*this->a12)-(this->a02*this->a11);
      double det_m21 = (this->a00*this->a12)-(this->a02*this->a10);
      double det_m22 = (this->a00*this->a11)-(this->a01*this->a10);
      Matrix3 cofactores(det_m00, -det_m01, det_m02,
                         -det_m10, det_m11, -det_m12,
                         det_m20, -det_m21, det_m22);
      return cofactores.transpose();
    }
    /**
     * @brief Clona la matriz actual.
     * @return Copia de la matriz actual.
     */
    Matrix3 clone() const {
      return Matrix3(this->a00, this->a01, this->a02,
                     this->a10, this->a11, this->a12,
                     this->a20, this->a21, this->a22);
    }
    /**
     * @brief Calcula el determinante de la matriz.
     * @return Determinante de la matriz.
     */
    double determinant() const {
      double det_m00 = (this->a11*this->a22)-(this->a12*this->a21);
      double det_m01 = (this->a10*this->a22)-(this->a12*this->a20);
      double det_m02 = (this->a10*this->a21)-(this->a11*this->a20);
      return this->a00*(det_m00) - this->a01*(det_m01) + this->a02*(det_m02);
    }
    /**
     * @brief Compara dos matrices con un epsilon.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @param e Epsilon para la comparación.
     * @return Verdadero si las matrices son aproximadamente iguales.
     */
    static bool equalsWithE(const Matrix3& m1, const Matrix3& m2, double e) {
      bool b00 = fabs(m1.a00-m2.a00) <= e;
      bool b01 = fabs(m1.a01-m2.a01) <= e;
      bool b02 = fabs(m1.a02-m2.a02) <= e;
      bool b10 = fabs(m1.a10-m2.a10) <= e;
      bool b11 = fabs(m1.a11-m2.a11) <= e;
      bool b12 = fabs(m1.a12-m2.a12) <= e;
      bool b20 = fabs(m1.a20-m2.a20) <= e;
      bool b21 = fabs(m1.a21-m2.a21) <= e;
      bool b22 = fabs(m1.a22-m2.a22) <= e;
      return b00 && b01 && b02 && b10 && b11 && b12 && b20 && b21 && b22;
    }
    /**
     * @brief Compara dos matrices con un epsilon predeterminado.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Verdadero si las matrices son aproximadamente iguales.
     */
    static bool equals(const Matrix3& m1, const Matrix3& m2) {
      double epsilon = 0.000001;
      return Matrix3::equalsWithE(m1, m2, epsilon);
    }
    /**
     * @brief Compara dos matrices exactamente.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Verdadero si las matrices son exactamente iguales.
     */
    static bool exactEquals(const Matrix3& m1, const Matrix3& m2) {
      return (m1.a00 == m2.a00)&&(m1.a01 == m2.a01)&&(m1.a02 == m2.a02)&&(m1.a10 == m2.a10)&&(m1.a11 == m2.a11)&&(m1.a12 == m2.a12)&&(m1.a20 == m2.a20)&&(m1.a21 == m2.a21)&&(m1.a22 == m2.a22);
    }
    /**
     * @brief Asigna la matriz a la matriz identidad.
     */
    void identity() {
      this->a00 = 1; this->a01 = 0; this->a02 = 0;
      this->a10 = 0; this->a11 = 1; this->a12 = 0;
      this->a20 = 0; this->a21 = 0; this->a22 = 1;
    }
    /**
     * @brief Calcula la inversa de la matriz.
     * @return Matriz inversa.
     */
    Matrix3 invert() const {
      double det = this->determinant();
      Matrix3 adjunta = this->adjoint();
      if (det == 0) {
        cout << "La matriz no tiene inversa" << endl;
        return Matrix3();
      }
      return Matrix3::multiplyScalar(adjunta, (1/det));
    }
    /**
     * @brief Multiplica dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matriz resultante de la multiplicación.
     */
    static Matrix3 multiply(const Matrix3& m1, const Matrix3& m2) {
      return Matrix3(
        (m1.a00*m2.a00) + (m1.a01*m2.a10) + (m1.a02*m2.a20),
        (m1.a00*m2.a01) + (m1.a01*m2.a11) + (m1.a02*m2.a21),
        (m1.a00*m2.a02) + (m1.a01*m2.a12) + (m1.a02*m2.a22),
        (m1.a10*m2.a00) + (m1.a11*m2.a10) + (m1.a12*m2.a20),
        (m1.a10*m2.a01) + (m1.a11*m2.a11) + (m1.a12*m2.a21),
        (m1.a10*m2.a02) + (m1.a11*m2.a12) + (m1.a12*m2.a22),
        (m1.a20*m2.a00) + (m1.a21*m2.a10) + (m1.a22*m2.a20),
        (m1.a20*m2.a01) + (m1.a21*m2.a11) + (m1.a22*m2.a21),
        (m1.a20*m2.a02) + (m1.a21*m2.a12) + (m1.a22*m2.a22)
      );
    }
    /**
     * @brief Multiplica una matriz por un escalar.
     * @param m1 Matriz a multiplicar.
     * @param c Escalar.
     * @return Matriz resultante de la multiplicación por el escalar.
     */
    static Matrix3 multiplyScalar(const Matrix3& m1, double c) {
      return Matrix3(
        m1.a00*c, m1.a01*c, m1.a02*c,
        m1.a10*c, m1.a11*c, m1.a12*c,
        m1.a20*c, m1.a21*c, m1.a22*c
      );
    }
    /**
     * @brief Multiplica una matriz por un vector.
     * @param v Vector a multiplicar.
     * @return Vector resultante de la multiplicación.
     */
    Vector3 multiplyVector(const Vector3& v) const {
      return Vector3(this->a00*v.getX()+this->a01*v.getY()+this->a02*v.getZ(),
                     this->a10*v.getX()+this->a11*v.getY()+this->a12*v.getZ(),
                     this->a20*v.getX()+this->a21*v.getY()+this->a22*v.getZ());
    }
    /**
     * @brief Crea una matriz de rotación.
     * @param theta Ángulo de rotación en radianes.
     * @return Matriz de rotación.
     */
    static Matrix3 rotate(double theta) {
      return Matrix3(cos(theta), -sin(theta), 0,
                     sin(theta), cos(theta), 0,
                     0, 0, 1);
    }
    /**
     * @brief Crea una matriz de escalamiento.
     * @param sx Factor de escala en el eje x.
     * @param sy Factor de escala en el eje y.
     * @return Matriz de escalamiento.
     */
    static Matrix3 scale(double sx, double sy) {
      return Matrix3(sx, 0, 0,
                     0, sy, 0,
                     0, 0, 1);
    }
    /**
     * @brief Asigna nuevos valores a la matriz.
     * @param a00 Elemento en la posición (0,0).
     * @param a01 Elemento en la posición (0,1).
     * @param a02 Elemento en la posición (0,2).
     * @param a10 Elemento en la posición (1,0).
     * @param a11 Elemento en la posición (1,1).
     * @param a12 Elemento en la posición (1,2).
     * @param a20 Elemento en la posición (2,0).
     * @param a21 Elemento en la posición (2,1).
     * @param a22 Elemento en la posición (2,2).
     */
    void set(double a00, double a01, double a02,
             double a10, double a11, double a12,
             double a20, double a21, double a22) {
      this->a00 = a00; this->a01 = a01; this->a02 = a02;
      this->a10 = a10; this->a11 = a11; this->a12 = a12;
      this->a20 = a20; this->a21 = a21; this->a22 = a22;
    }
    /**
     * @brief Resta dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matriz resultante de la resta.
     */
    static Matrix3 subtract(const Matrix3& m1, const Matrix3& m2) {
      return Matrix3(
        m1.a00-m2.a00, m1.a01-m2.a01, m1.a02-m2.a02,
        m1.a10-m2.a10, m1.a11-m2.a11, m1.a12-m2.a12,
        m1.a20-m2.a20, m1.a21-m2.a21, m1.a22-m2.a22
      );
    }
    /**
     * @brief Crea una matriz de translación.
     * @param tx Desplazamiento en el eje x.
     * @param ty Desplazamiento en el eje y.
     * @return Matriz de translación.
     */
    static Matrix3 translate(double tx, double ty) {
      return Matrix3(1, 0, tx,
                     0, 1, ty,
                     0, 0, 1);
    }
    /**
     * @brief Calcula la transpuesta de la matriz.
     * @return Matriz transpuesta.
     */
    Matrix3 transpose() const {
      return Matrix3(this->a00, this->a10, this->a20,
                     this->a01, this->a11, this->a21,
                     this->a02, this->a12, this->a22);
    }

    static Matrix3 viewport(double w, double h){
      return Matrix3(w/2.0, 0, w/2.0,
                     0, h/2.0, h/2.0,
                     0, 0, 1);
    }
};
/**
 * @class Matrix4
 * @brief La clase Matrix4 representa matrices de 4 × 4 y se utiliza para la representación y construcción de transformaciones en tres dimensiones.
 */
class Matrix4 {
public:
    double a00, a01, a02, a03;
    double a10, a11, a12, a13;
    double a20, a21, a22, a23;
    double a30, a31, a32, a33;
    /**
     * @brief Constructor que inicializa una matriz 4x4 con valores por defecto.
     * @param a00 Valor para el elemento (0,0).
     * @param a01 Valor para el elemento (0,1).
     * @param a02 Valor para el elemento (0,2).
     * @param a03 Valor para el elemento (0,3).
     * @param a10 Valor para el elemento (1,0).
     * @param a11 Valor para el elemento (1,1).
     * @param a12 Valor para el elemento (1,2).
     * @param a13 Valor para el elemento (1,3).
     * @param a20 Valor para el elemento (2,0).
     * @param a21 Valor para el elemento (2,1).
     * @param a22 Valor para el elemento (2,2).
     * @param a23 Valor para el elemento (2,3).
     * @param a30 Valor para el elemento (3,0).
     * @param a31 Valor para el elemento (3,1).
     * @param a32 Valor para el elemento (3,2).
     * @param a33 Valor para el elemento (3,3).
     */
    Matrix4(double a00 = 1, double a01 = 0, double a02 = 0, double a03 = 0,
            double a10 = 0, double a11 = 1, double a12 = 0, double a13 = 0,
            double a20 = 0, double a21 = 0, double a22 = 1, double a23 = 0,
            double a30 = 0, double a31 = 0, double a32 = 0, double a33 = 1) {
              this->a00 = a00; this->a01 = a01; this->a02 = a02; this->a03 = a03;
              this->a10 = a10; this->a11 = a11; this->a12 = a12; this->a13 = a13;
              this->a20 = a20; this->a21 = a21; this->a22 = a22; this->a23 = a23;
              this->a30 = a30; this->a31 = a31; this->a32 = a32; this->a33 = a33;
    }
    /**
     * @brief Devuelve la suma de dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matrix4 Resultado de la suma de m1 y m2.
     */
    static Matrix4 add(const Matrix4& m1, const Matrix4& m2) {
      return Matrix4(m1.a00+m2.a00, m1.a01+m2.a01, m1.a02+m2.a02, m1.a03+m2.a03,
                     m1.a10+m2.a10, m1.a11+m2.a11, m1.a12+m2.a12, m1.a13+m2.a13,
                     m1.a20+m2.a20, m1.a21+m2.a21, m1.a22+m2.a22, m1.a23+m2.a23,
                     m1.a30+m2.a30, m1.a31+m2.a31, m1.a32+m2.a32, m1.a33+m2.a33);
    }
    /**
     * @brief Devuelve la matriz adjunta de la matriz actual.
     * @return Matrix4 Matriz adjunta.
     */
    Matrix4 adjoint() const {
      Matrix3 m00(this->a11, this->a12, this->a13, this->a21, this->a22, this->a23, this->a31, this->a32, this->a33);
      Matrix3 m10(this->a01, this->a02, this->a03, this->a21, this->a22, this->a23, this->a31, this->a32, this->a33);
      Matrix3 m20(this->a01, this->a02, this->a03, this->a11, this->a12, this->a13, this->a31, this->a32, this->a33);
      Matrix3 m30(this->a01, this->a02, this->a03, this->a11, this->a12, this->a13, this->a21, this->a23, this->a23);
      Matrix3 m01(this->a10, this->a12, this->a13, this->a20, this->a22, this->a23, this->a30, this->a32, this->a33);
      Matrix3 m11(this->a00, this->a02, this->a03, this->a20, this->a22, this->a23, this->a30, this->a32, this->a33);
      Matrix3 m21(this->a00, this->a02, this->a03, this->a10, this->a12, this->a13, this->a30, this->a32, this->a33);
      Matrix3 m31(this->a00, this->a02, this->a03, this->a10, this->a12, this->a13, this->a20, this->a22, this->a23);
      Matrix3 m02(this->a10, this->a11, this->a13, this->a20, this->a21, this->a23, this->a30, this->a31, this->a33);
      Matrix3 m12(this->a00, this->a01, this->a03, this->a20, this->a21, this->a23, this->a30, this->a31, this->a33);
      Matrix3 m22(this->a00, this->a01, this->a03, this->a10, this->a11, this->a13, this->a30, this->a31, this->a33);
      Matrix3 m32(this->a00, this->a01, this->a03, this->a10, this->a11, this->a13, this->a20, this->a21, this->a23);
      Matrix3 m03(this->a10, this->a11, this->a12, this->a20, this->a21, this->a22, this->a30, this->a31, this->a32);
      Matrix3 m13(this->a00, this->a01, this->a02, this->a20, this->a21, this->a22, this->a30, this->a31, this->a32);
      Matrix3 m23(this->a00, this->a01, this->a02, this->a10, this->a11, this->a12, this->a30, this->a31, this->a32);
      Matrix3 m33(this->a00, this->a01, this->a02, this->a10, this->a11, this->a12, this->a20, this->a21, this->a22);
      Matrix4 cofactores(m00.determinant(),-m01.determinant(), m02.determinant(),-m03.determinant(),
                        -m10.determinant(), m11.determinant(),-m12.determinant(), m13.determinant(),
                         m20.determinant(),-m21.determinant(), m22.determinant(),-m23.determinant(),
                        -m30.determinant(), m31.determinant(),-m32.determinant(), m33.determinant());
      return cofactores.transpose();
    }
    /**
     * @brief Devuelve una copia del objeto Matrix4.
     * @return Matrix4 Copia del objeto actual.
     */
    Matrix4 clone() const {
      return Matrix4(this->a00, this->a01, this->a02, this->a03,
                     this->a10, this->a11, this->a12, this->a13,
                     this->a20, this->a21, this->a22, this->a23,
                     this->a30, this->a31, this->a32, this->a33);
    }
    /**
     * @brief Calcula el determinante de la matriz.
     * @return double Determinante de la matriz.
     */
    double determinant() const {
      Matrix3 m00(this->a11, this->a12, this->a13, this->a21, this->a22, this->a23, this->a31, this->a32, this->a33);
      Matrix3 m01(this->a10, this->a12, this->a13, this->a20, this->a22, this->a23, this->a30, this->a32, this->a33);
      Matrix3 m02(this->a10, this->a11, this->a13, this->a20, this->a21, this->a23, this->a30, this->a31, this->a33);
      Matrix3 m03(this->a10, this->a11, this->a12, this->a20, this->a21, this->a22, this->a30, this->a31, this->a32);
      return (this->a00*m00.determinant())-(this->a01*m01.determinant())+(this->a02*m02.determinant())-(this->a03*m03.determinant());
    }
    /**
     * @brief Verifica si dos matrices son aproximadamente iguales.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @param epsilon Tolerancia para la comparación.
     * @return bool True si las matrices son aproximadamente iguales, false en caso contrario.
     */
    static bool equalsWithE(const Matrix4& m1, const Matrix4& m2, double epsilon) {
      bool b00 = fabs(m1.a00-m2.a00) <= epsilon;
      bool b01 = fabs(m1.a01-m2.a01) <= epsilon;
      bool b02 = fabs(m1.a02-m2.a02) <= epsilon;
      bool b03 = fabs(m1.a03-m2.a03) <= epsilon;
      bool b10 = fabs(m1.a10-m2.a10) <= epsilon;
      bool b11 = fabs(m1.a11-m2.a11) <= epsilon;
      bool b12 = fabs(m1.a12-m2.a12) <= epsilon;
      bool b13 = fabs(m1.a13-m2.a13) <= epsilon;
      bool b20 = fabs(m1.a20-m2.a20) <= epsilon;
      bool b21 = fabs(m1.a21-m2.a21) <= epsilon;
      bool b22 = fabs(m1.a22-m2.a22) <= epsilon;
      bool b23 = fabs(m1.a23-m2.a23) <= epsilon;
      bool b30 = fabs(m1.a30-m2.a30) <= epsilon;
      bool b31 = fabs(m1.a31-m2.a31) <= epsilon;
      bool b32 = fabs(m1.a32-m2.a32) <= epsilon;
      bool b33 = fabs(m1.a33-m2.a33) <= epsilon;
      return b00 && b01 && b02 && b03 && b10 && b11 && b12 && b13 && b20 && b21 && b22 && b23 && b30 && b31 && b32 && b33;
    }
    /**
     * @brief Multiplica la matriz por un escalar.
     * @param scalar Escalar por el cual multiplicar la matriz.
     * @return Matrix4 Resultado de la multiplicación por el escalar.
     */
    Matrix4 multiplyByScalar(double scalar) const {
      return Matrix4(this->a00*scalar, this->a01*scalar, this->a02*scalar, this->a03*scalar,
                     this->a10*scalar, this->a11*scalar, this->a12*scalar, this->a13*scalar,
                     this->a20*scalar, this->a21*scalar, this->a22*scalar, this->a23*scalar,
                     this->a30*scalar, this->a31*scalar, this->a32*scalar, this->a33*scalar);
    }
    /**
     * @brief Multiplica dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matrix4 Resultado de la multiplicación de m1 y m2.
     */
    static Matrix4 multiply(const Matrix4& m1, const Matrix4& m2) {
      return Matrix4(
        (m1.a00*m2.a00) + (m1.a01*m2.a10) + (m1.a02*m2.a20) + (m1.a03*m2.a30),
        (m1.a00*m2.a01) + (m1.a01*m2.a11) + (m1.a02*m2.a21) + (m1.a03*m2.a31),
        (m1.a00*m2.a02) + (m1.a01*m2.a12) + (m1.a02*m2.a22) + (m1.a03*m2.a32),
        (m1.a00*m2.a03) + (m1.a01*m2.a13) + (m1.a02*m2.a23) + (m1.a03*m2.a33),
        (m1.a10*m2.a00) + (m1.a11*m2.a10) + (m1.a12*m2.a20) + (m1.a13*m2.a30),
        (m1.a10*m2.a01) + (m1.a11*m2.a11) + (m1.a12*m2.a21) + (m1.a13*m2.a31),
        (m1.a10*m2.a02) + (m1.a11*m2.a12) + (m1.a12*m2.a22) + (m1.a13*m2.a32),
        (m1.a10*m2.a03) + (m1.a11*m2.a13) + (m1.a12*m2.a23) + (m1.a13*m2.a33),
        (m1.a20*m2.a00) + (m1.a21*m2.a10) + (m1.a22*m2.a20) + (m1.a23*m2.a30),
        (m1.a20*m2.a01) + (m1.a21*m2.a11) + (m1.a22*m2.a21) + (m1.a23*m2.a31),
        (m1.a20*m2.a02) + (m1.a21*m2.a12) + (m1.a22*m2.a22) + (m1.a23*m2.a32),
        (m1.a20*m2.a03) + (m1.a21*m2.a13) + (m1.a22*m2.a23) + (m1.a23*m2.a33),
        (m1.a30*m2.a00) + (m1.a31*m2.a10) + (m1.a32*m2.a20) + (m1.a33*m2.a30),
        (m1.a30*m2.a01) + (m1.a31*m2.a11) + (m1.a32*m2.a21) + (m1.a33*m2.a31),
        (m1.a30*m2.a02) + (m1.a31*m2.a12) + (m1.a32*m2.a22) + (m1.a33*m2.a32),
        (m1.a30*m2.a03) + (m1.a31*m2.a13) + (m1.a32*m2.a23) + (m1.a33*m2.a33)
      );
    }
    /**
     * @brief Invierte la matriz actual.
     * @return Matrix4 Matriz invertida.
     * @throws std::runtime_error Si la matriz es singular (determinante cercano a cero).
     */
    Matrix4 invert() const {
      double det = this->determinant();
      Matrix4 adjunta = this->adjoint();
      if (det == 0) {
        throw runtime_error("La matriz es singular (determinante cercano a cero)");
      }
      return adjunta.multiplyByScalar(1/det);
    }
    /**
     * @brief Establece la matriz como una matriz identidad.
     * @return Matrix4& Referencia a la matriz actual.
     */
    Matrix4& identity() {
      this->a00 = 1; this->a01 = 0; this->a02 = 0; this->a03 = 0;
      this->a10 = 0; this->a11 = 1; this->a12 = 0; this->a13 = 0;
      this->a20 = 0; this->a21 = 0; this->a22 = 1; this->a23 = 0;
      this->a30 = 0; this->a31 = 0; this->a32 = 0; this->a33 = 1;
      return *this;
    }
    /**
     * @brief Multiplica cada componente de una matriz por un escalar.
     * @param m1 Matriz a multiplicar.
     * @param c Escalar por el cual multiplicar la matriz.
     * @return Matrix4 Resultado de la multiplicación por el escalar.
     */
    static Matrix4 multiplyScalar(const Matrix4& m1, double c) {
      return Matrix4(
        m1.a00*c, m1.a01*c, m1.a02*c, m1.a03*c,
        m1.a10*c, m1.a11*c, m1.a12*c, m1.a13*c,
        m1.a20*c, m1.a21*c, m1.a22*c, m1.a23*c,
        m1.a30*c, m1.a31*c, m1.a32*c, m1.a33*c
      );
    }
    /**
     * @brief Multiplica un vector por la matriz.
     * @param v Vector a multiplicar.
     * @return Vector4 Resultado de la multiplicación del vector por la matriz.
     */
    Vector4 multiplyVector(const Vector4& v) const {
      return Vector4(this->a00*v.getX()+this->a01*v.getY()+this->a02*v.getZ()+this->a03*v.getW(),
                     this->a10*v.getX()+this->a11*v.getY()+this->a12*v.getZ()+this->a13*v.getW(),
                     this->a20*v.getX()+this->a21*v.getY()+this->a22*v.getZ()+this->a23*v.getW(),
                     this->a30*v.getX()+this->a31*v.getY()+this->a32*v.getZ()+this->a33*v.getW());
    }
    /**
     * @brief Establece nuevos valores para los elementos de la matriz.
     * @param a00 Valor para el elemento (0,0).
     * @param a01 Valor para el elemento (0,1).
     * @param a02 Valor para el elemento (0,2).
     * @param a03 Valor para el elemento (0,3).
     * @param a10 Valor para el elemento (1,0).
     * @param a11 Valor para el elemento (1,1).
     * @param a12 Valor para el elemento (1,2).
     * @param a13 Valor para el elemento (1,3).
     * @param a20 Valor para el elemento (2,0).
     * @param a21 Valor para el elemento (2,1).
     * @param a22 Valor para el elemento (2,2).
     * @param a23 Valor para el elemento (2,3).
     * @param a30 Valor para el elemento (3,0).
     * @param a31 Valor para el elemento (3,1).
     * @param a32 Valor para el elemento (3,2).
     * @param a33 Valor para el elemento (3,3).
     * @return Matrix4& Referencia a la matriz actual.
     */
    Matrix4& set(double a00, double a01, double a02, double a03,
                 double a10, double a11, double a12, double a13,
                 double a20, double a21, double a22, double a23,
                 double a30, double a31, double a32, double a33) {
      this->a00 = a00; this->a01 = a01; this->a02 = a02; this->a03 = a03;
      this->a10 = a00; this->a11 = a01; this->a12 = a02; this->a13 = a13;
      this->a20 = a00; this->a21 = a01; this->a22 = a02; this->a23 = a23;
      this->a30 = a00; this->a31 = a01; this->a32 = a02; this->a33 = a33;
      return *this;
    }
    /**
     * @brief Devuelve la resta de dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matrix4 Resultado de la resta de m1 y m2.
     */
    static Matrix4 subtract(const Matrix4& m1, const Matrix4& m2) {
      return Matrix4(
        m1.a00-m2.a00, m1.a01-m2.a01, m1.a02-m2.a02, m1.a03-m2.a03,
        m1.a10-m2.a10, m1.a11-m2.a11, m1.a12-m2.a12, m1.a13-m2.a13,
        m1.a20-m2.a20, m1.a21-m2.a21, m1.a22-m2.a22, m1.a23-m2.a23,
        m1.a30-m2.a30, m1.a31-m2.a31, m1.a32-m2.a32, m1.a33-m2.a33
      );
    }
    /**
     * @brief Devuelve la transpuesta de la matriz actual.
     * @return Matrix4 Matriz transpuesta.
     */
    Matrix4 transpose() const {
      return Matrix4(
        this->a00, this->a10, this->a20, this->a30,
        this->a01, this->a11, this->a21, this->a31,
        this->a02, this->a12, this->a22, this->a32,
        this->a03, this->a13, this->a23, this->a33
      );
    }
    // Métodos estáticos de matrices de transformaciones de cámara
    /**
     * @brief Genera una matriz de proyección de perspectiva utilizando un frustum.
     *
     * @param left Límite izquierdo del frustum.
     * @param right Límite derecho del frustum.
     * @param bottom Límite inferior del frustum.
     * @param top Límite superior del frustum.
     * @param near Distancia del plano cercano.
     * @param far Distancia del plano lejano.
     * @return Matrix4 Matriz 4x4 que define el frustum.
     */
    static Matrix4 frustum(double left, double right, double bottom, double top, double near, double far) {
        return Matrix4(
          (2*near)/(right-left), 0, 0, -(right+left)/(right-left),
          0, (2*near)/(top-bottom), 0, -(top+bottom)/(top-bottom),
          0, 0, -(far+near)/(far-near), -(2*near*far)/(far-near),
          0, 0, -1, 0
        );
    }
    /**
     * @brief Genera una matriz de vista para una cámara en una posición dada.
     *
     * @param eye Posición de la cámara.
     * @param center Punto al que la cámara está mirando.
     * @param up Vector hacia arriba en el espacio de la cámara.
     * @return Matrix4 Matriz 4x4 que define la vista.
     */
    static Matrix4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up) {
      Vector3 w = Vector3::subtract(eye, center);
      w = w.normalize();
      Vector3 u = Vector3::cross(up, w);
      u = u.normalize();
      Vector3 v = Vector3::cross(w, u);
      v = v.normalize();
      return Matrix4(
        u.getX(), u.getY(), u.getZ(), -(Vector3::dot(eye, u)),
        v.getX(), v.getY(), v.getZ(), -(Vector3::dot(eye, v)),
        w.getX(), w.getY(), w.getZ(), -(Vector3::dot(eye, w)),
        0, 0, 0, 1
      );
    }
    /**
     * @brief Genera una matriz de proyección ortográfica.
     *
     * @param left Límite izquierdo de la proyección.
     * @param right Límite derecho de la proyección.
     * @param bottom Límite inferior de la proyección.
     * @param top Límite superior de la proyección.
     * @param near Distancia del plano cercano.
     * @param far Distancia del plano lejano.
     * @return Matrix4 Matriz 4x4 que define la proyección ortográfica.
     */
    static Matrix4 orthographic(double left, double right, double bottom, double top, double near, double far) {
        return Matrix4(
          2/(right-left), 0, 0, -(right+left)/(right-left),
          0, 2/(top-bottom), 0, -(top+bottom)/(top-bottom),
          0, 0, 2/(near-far), -(far+near)/(near-far),
          0, 0, 0, 1
        );
    }
    /**
     * @brief Genera una matriz de proyección de perspectiva utilizando un campo de visión.
     *
     * @param fovy Campo de visión en el eje vertical, en grados.
     * @param aspect Relación de aspecto (ancho/alto).
     * @param near Distancia del plano cercano.
     * @param far Distancia del plano lejano.
     * @return Matrix4 Matriz 4x4 que define la proyección de perspectiva.
     */
    static Matrix4 perspective(double fovy, double aspect, double near, double far) {
      double fovRad = fovy*(M_PI/180.0);
      double c = 1/tan(fovRad/2);
      return Matrix4(
        c/aspect, 0, 0, 0,
        0, c, 0, 0,
        0, 0, -(far+near)/(far-near), -(2*near*far)/(far-near),
        0, 0, -1, 0
      );
    }
    /**
     * @brief Genera una matriz de rotación alrededor del eje X.
     *
     * @param theta Ángulo de rotación en radianes.
     * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje X.
     */
    static Matrix4 rotateX(double theta) {
        return Matrix4(
          1, 0, 0, 0,
          0, cos(theta), -sin(theta), 0,
          0, sin(theta), cos(theta), 0,
          0, 0, 0, 1
        );
    }
    /**
     * @brief Genera una matriz de rotación alrededor del eje Y.
     *
     * @param theta Ángulo de rotación en radianes.
     * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje Y.
     */
    static Matrix4 rotateY(double theta) {
        return Matrix4(
          cos(theta), 0, sin(theta), 0,
          0, 1, 0, 0,
          -sin(theta), 0, cos(theta), 0,
          0, 0, 0, 1
        );
    }
    /**
     * @brief Genera una matriz de rotación alrededor del eje Z.
     *
     * @param theta Ángulo de rotación en radianes.
     * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje z.
     */
    static Matrix4 rotateZ(double theta) {
        return Matrix4(
          cos(theta), -sin(theta), 0, 0,
          sin(theta), cos(theta), 0, 0,
          0, 0, 1, 0,
          0, 0, 0, 1
        );
    }
    /**
     * @brief Genera una matriz de escalado.
     *
     * @param x Factor de escala en el eje X.
     * @param y Factor de escala en el eje Y.
     * @param z Factor de escala en el eje Z.
     * @return Matrix4 Matriz 4x4 que define el escalado.
     */
    static Matrix4 scale(double x, double y, double z) {
        return Matrix4(
          x, 0, 0, 0,
          0, y, 0, 0,
          0, 0, z, 0,
          0, 0, 0, 1
        );
    }
    /**
     * @brief Genera una matriz de traslación.
     *
     * @param x Desplazamiento en el eje X.
     * @param y Desplazamiento en el eje Y.
     * @param z Desplazamiento en el eje Z.
     * @return Matrix4 Matriz 4x4 que define la traslación.
     */
    static Matrix4 translate(double x, double y, double z) {
        return Matrix4(
          1, 0, 0, x,
          0, 1, 0, y,
          0, 0, 1, z,
          0, 0, 0, 1
        );
    }
};

inline std::ostream& operator<<(std::ostream& out, const Vector3& v){
  return out << "[" << v.getX() << '\n'
             << " " << v.getY() << '\n'
             << " " << v.getZ() << "]";
}

inline std::ostream& operator<<(std::ostream& out, const Vector4& v){
  return out << "[" << v.getX() << '\n'
             << " " << v.getY() << '\n'
             << " " << v.getZ() << '\n'
             << " " << v.getW() << "]";
}

inline std::ostream& operator<<(std::ostream& out, const Matrix3& m){
  return out << "[" << m.a00 << " " << m.a01 << " " << m.a02 << '\n'
             << " " << m.a10 << " " << m.a11 << " " << m.a12 << '\n'
             << " " << m.a20 << " " << m.a21 << " " << m.a22 << "]";
}

inline std::ostream& operator<<(std::ostream& out, const Matrix4& m){
  return out << "[" << m.a00 << " " << m.a01 << " " << m.a02 << " " << m.a03 << '\n'
             << " " << m.a10 << " " << m.a11 << " " << m.a12 << " " << m.a13 << '\n'
             << " " << m.a20 << " " << m.a21 << " " << m.a22 << " " << m.a23 << '\n'
             << " " << m.a30 << " " << m.a31 << " " << m.a32 << " " << m.a33 << "]";
}
