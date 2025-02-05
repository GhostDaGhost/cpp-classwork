class Complex {
	public:
		double real;
		double imaginary;

		// CONSTRUCTOR
		Complex(double newReal, double newImaginary) {
			real = newReal;
			imaginary = newImaginary;
		}

		// ADDITION
		Complex addition(Complex& other) {
			return Complex(real + other.real, imaginary + other.imaginary);
		}

		// SUBTRACTION
		Complex subtraction(Complex& other) {
			return Complex(real - other.real, imaginary - other.imaginary);
		}

		// MULTIPLICATION
		Complex multiplication(Complex& other) {
			return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
		}
};
