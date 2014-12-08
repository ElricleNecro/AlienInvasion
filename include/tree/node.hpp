#ifndef NODE_HPP_2OSCA1YP
#define NODE_HPP_2OSCA1YP

#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <initializer_list>

#include "math/point.hpp"
#include "config.hpp"

namespace tree
{
	class BuildError : public std::exception
	{
		public:
			BuildError(const char* Msg);
			BuildError(const std::string &Msg);
			BuildError(const BuildError& old);
			virtual ~BuildError(void) noexcept;

			virtual const char* what(void) const noexcept;

		private:
			std::string msg;
	};

	typedef void SwapFunc(math::Point<F_TYPE> *a, math::Point<F_TYPE> *b);

    class Node {
    	public:
    		Node(I_TYPE* part,
    			const int NbPart,
    			const int NbMin,
    			std::initializer_list<double> center,
    			const double size,
    			const unsigned int level=0,
    			Node *parent=NULL
                   );
    		Node(I_TYPE* part,
    			const int NbPart,
    			const int NbMin,
    			const double center[3],
    			const double size,
    			const unsigned int level=0,
    			Node *parent=NULL
    		       );
    		Node(const Node &obj);
    		virtual ~Node(void);

    		bool Build(void);

    		// Node Mover :
    		Node* Up(void);
    		Node* Down(void);
    		Node* Next(void);

    		bool In(math::Point<F_TYPE> *part);
    		Node* GetNodeOf(math::Point<F_TYPE> *part);

    		// Some setter and getter :
    		int    GetLevelMax(void) const;
    		void   SetLevelMax(int newlevel);

    		int SetPart(void);
            // io::types::Particules GetPart(void);

    		void SetSwapFunction(SwapFunc *func);

    		const double* GetCenter(void) const;

    		int GetN(void) const;
    		int GetLevel(void) const;
    		double GetSize(void) const;

    		const double* GetMassCenter(void) const;
    		double GetTotalMass(void) const;

    		std::string GetError(void);

    		int GetDeep(void) const;

    	private:
    		Node(const Node &obj, Node *parent);

    		unsigned int level;		/*< Niveau du noeud dans l'arbre.*/
    		double Pos[3];			/*< Coordonnées du centre géometrique du carré.*/
    		double cote;			/*< Longueur du côté du carré.*/
    		void build_level(void);
    		std::string error = "";

    	protected:
    		Node *frere,
    			*fils,
    			*parent;
            I_TYPE *first;	/*< Pointeur vers la particule du tableau de particule.*/
    		double cm[3];			/*< Position du centre de masse de la cellule.*/
    		double M_cm;			/*< Masse totale dans la cellule.*/
    		int N,				/*< Nombre de particule contenue dans le noeud.*/
    		    Level_Max,
    		    NB_Bro = 8,
    		    Leaf;
    		SwapFunc *Swap = NULL;
    };
} /* tree */

#endif /* end of include guard: NODE_HPP_2OSCA1YP */
