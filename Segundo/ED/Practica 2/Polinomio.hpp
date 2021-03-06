/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>
#include <list>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:
		std::vector<ed::Monomio> monomios_;


   //! \name Funciones o métodos públicos de la clase Polinomio
   public:
		//! \name Constructores de la clase Polinomio
		Polinomio(){
			Monomio nulo;
			nulo.setCoeficiente(0.0);
			nulo.setGrado(0);
			this->InsertaMonomio(nulo);
		};

		Polinomio(Polinomio const &copia){
			this->setMonomios(copia.getMonomios());
		};


		//! \name Observadores: funciones de consulta de la clase Polinomio
		/**
		 * @brief Devuelve el vector de monomios del polinomio
		 * 
		 * @return std::vector<Monomio>: Vector de monomios
		 */
		inline std::vector<ed::Monomio> getMonomios() const {return monomios_;};


		/**
		 * @brief Devuelve el grado del Polinomio
		 * 
		 * @return int: Grado del polinomio
		 */
		inline int getGrado() const {return this->getMonomios()[0].getGrado();};


		/**
		 * @brief Comprueba si el Polinomio es nulo
		 * 
		 * @return true 
		 * @return false 
		 */
		bool esNulo() const;


		/**
		 * @brief Devuelve el numero de monomios que hay en el polinomio
		 * 
		 * @return int: Numero de monomios
		 */
		inline int getNumeroMonomios() const {return this->getMonomios().size();};


		/**
		 * @brief Comprueba si el monomio de grado mGrado existe
		 * 
		 * @param mGrado: Grado del monomio que buscamos
		 * @return true si existe
		 * @return false si no existe
		 */
		bool existeMonomio(int mGrado) const;


		/**
		 * @brief Devuelve el monomio de grado mGrado
		 * 
		 * @param mGrado: Grado del monomio que buscamos
		 * @return ed::Monomio si lo encuentra
		 * @return ed::Monomio Nulo si no lo encuentra
		 */
		ed::Monomio & getMonomio(int mGrado);


		//! \name Funciones de modificación de la clase Polinomio
		/**
		 * @brief Inserta un monomio en el polinomio
		 * 
		 * @param nuevo_monomio: Monomio a insertar
		 */
		void InsertaMonomio(Monomio const &nuevo_monomio);


		/**
		 * @brief Cambia todos los monomios del polinomio por el vector nueva_lista
		 * 
		 * @param nuevo_vector: Nuevo vector de monomios
		 */
		inline void setMonomios(std::vector<Monomio> const &nuevo_vector){this->monomios_ = nuevo_vector;};

		////////////////////////////////////////////////////////////////

		//! \name Operadores de la clase Polinomio

		/**
		 * @brief Operador de asignacion Polinomio Polinomio
		 * 
		 * @param p :Polinomio que se va a asignar
		 * @return Polinomio& 
		 */
		Polinomio & operator=(Polinomio const &p);

		/**
		 * @brief Operador de asignacion Polinomio Monomio
		 * 
		 * @param m 
		 * @return Polinomio& 
		 */
		Polinomio & operator=(Monomio const &m);

		/**
		 * @brief Operador de asignacion Polinomio Real
		 * 
		 * @param x 
		 * @return Polinomio& 
		 */
		Polinomio & operator=(double const &x);

		// Operadores aritméticos y asignación

		/**
		 * @brief Operador de suma y asiganción Polinomio Polinomio
		 * 
		 * @param p 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(Polinomio const &p);


		/**
		 * @brief Operador de suma y asiganción Polinomio Monomio
		 * 
		 * @param m 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(ed::Monomio const &m);

		/**
		 * @brief Operador de suma y asiganción Polinomio Real
		 * 
		 * @param m 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(double const &x);

		/**
		 * @brief Operador de resta y asiganción Polinomio Polinomio
		 * 
		 * @param p 
		 * @return Polinomio& 
		 */
		Polinomio & operator-=(Polinomio const &p);

		/**
		 * @brief Operador de resta y asiganción Polinomio Monomio
		 * 
		 * @param m 
		 * @return Polinomio& 
		 */
		Polinomio & operator-=(ed::Monomio const &m);


		/**
		 * @brief Operador de resta y asiganción Polinomio Real
		 * 
		 * @param x 
		 * @return Polinomio& 
		 */
		Polinomio & operator-=(double const &x);

		/**
		 * @brief Operador de producto y asiganción Polinomio Polinomio
		 * 
		 * @param p 
		 * @return Polinomio& 
		 */
		Polinomio & operator*=(Polinomio const &p);

		/**
		 * @brief Operador de producto y asiganción Polinomio Monomio
		 * 
		 * @param m 
		 * @return Polinomio& 
		 */
		Polinomio & operator*=(ed::Monomio const &m);

		/**
		 * @brief Operador de producto y asiganción Polinomio Real
		 * 
		 * @param x 
		 * @return Polinomio& 
		 */
		Polinomio & operator*=(double const &x);
		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Polinomio
		/**
		 * @brief Lectura de un polinomio por teclado
		 * 
		 */
		void leerPolinomio();

		/**
		 * @brief Imprime un polinomio por terminal
		 * 
		 */
		void escribirPolinomio();


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Polinomio
		/**
		 * @brief Ordena el polinomio de mayor a menor grado
		 * 
		 */
		void ordenarPolinomio();

		/**
		 * @brief Calcula el valor de un polinomio para x
		 * 
		 */
		double calcularValor(double x);


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
