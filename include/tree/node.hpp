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
	template<typename T>
	std::string convert(T number);

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

	template<class T>
	class Node {
		public:
			Node(
				I_TYPE* part,
				const int NbPart,
				const int NbMin,
				std::initializer_list<double> center,
				const double size,
				const unsigned int level=0,
				Node *parent=NULL
			);
			Node(
				I_TYPE* part,
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

			bool In(math::Point<F_TYPE>& part);
			Node* GetNodeOf(math::Point<F_TYPE>& part);

			// Some setter and getter :
			int    GetLevelMax(void) const;
			void   SetLevelMax(int newlevel);

			int SetPart(T& part)
			{
				int used = 0;

				for(int i=0; i<this->N; i++)
				{
					if( this->In(part[ this->first[i] ]) )
					{
						if( i != used )
						{
							// io::types::Swap( &this->first[i], &this->first[used]);
						}
						used++;
					}
				}

				return used;
			};

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
			void build_level(T& part)
			{
				int       NbUsed  = 0;
				double    NewSide = this->cote * 0.25,
					  x_g     = 0.,
					  y_g     = 0.,
					  z_g     = 0.;
				Node **tmp     = &(this->fils);

				for(int i=0; i<this->NB_Bro; i++)
				{
					if( (i & 1) == 0 )
						x_g = this->Pos[0] + NewSide;
					else
						x_g = this->Pos[0] - NewSide;

					if( (i & 2) == 0 )
						y_g = this->Pos[1] + NewSide;
					else
						y_g = this->Pos[1] - NewSide;

					if( (i & 4) == 0 )
						z_g = this->Pos[2] + NewSide;
					else
						z_g = this->Pos[2] - NewSide;

					*tmp = new Node(
							&this->first[NbUsed],
							this->N - NbUsed,
							this->Leaf,
							{
							x_g,
							y_g,
							z_g
							},
							this->cote * 0.5,
							this->level + 1,
							this
					);

					//int used = this->setPart(*tmp, to_build->N - NbUsed);
					int used = (*tmp)->SetPart(part);
					if( used != 0 )
					{
						//std::cout << "Son(" << this->level << ") " << i << ": " << tmp << " " << *tmp << " " << std::endl;
						(*tmp)->N = used;
						if( used > this->Leaf )
						{
							//if( !(*tmp)->build_level() )
							(*tmp)->Build();
						}
						NbUsed += used;
						tmp = &((*tmp)->frere);
					}
					else
					{
						delete *tmp;
						*tmp = NULL;
					}
				}

				if( NbUsed != this->N )
				{
					this->error = "Some Particles were not distributed at level " + convert<int>(this->level) + " : " + convert<int>(NbUsed) + ", " + convert<int>(this->N);
					std::string except = "Some Particles were not distributed at level " + convert<int>(this->level) +
						": " + convert<int>(NbUsed) + ", " + convert<int>(this->N) + "\n";
					//for(int i = NbUsed; i < this->N; i++)
					//{
					//except = except + "Particle " + convert<int>(i) + " ";
					//std::cerr << "\033[32m";
					//for(int j = 0; j < 3; j++)
					//{
					//std::cerr << this->first[i].Pos[j] << " (" << convert<float>(this->first[i].Pos[j]) << ")\t";
					//except = except + convert<float>(this->first[i].Pos[j]) + " ";
					//}
					//std::cerr << "\033[00m" << std::endl;
					//except = except + "\n";
					//}
					throw BuildError(except);
				}
			}
			std::string error = "";

		protected:
			Node *frere,
			     *fils,
			     *parent;
			I_TYPE *first;			/*< Pointeur vers la particule du tableau de particule.*/
			int N,				/*< Nombre de particule contenue dans le noeud.*/
			    Level_Max,
			    NB_Bro = 8,
			    Leaf;
	};
} /* tree */

#endif /* end of include guard: NODE_HPP_2OSCA1YP */
