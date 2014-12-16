#ifndef TREE_HPP_KZEPLQJS
#define TREE_HPP_KZEPLQJS

#include <initializer_list>

namespace tree
{
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
		}

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

				int used = (*tmp)->SetPart(part);
				if( used != 0 )
				{
					(*tmp)->N = used;
					if( used > this->Leaf )
					{
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
				throw BuildError(except);
			}
		}
} /* tree */

#endif /* end of include guard: TREE_HPP_KZEPLQJS */

