#include "tree/node.hpp"

namespace tree
{
	template<typename T>
	std::string convert(T number)
	{
		std::stringstream ss;//create a stringstream
		ss << number;//add number to the stream
		return ss.str();//return a string with the contents of the stream
	}

	BuildError::BuildError(const char* Msg)
	: msg(Msg)
	{
	}

	BuildError::BuildError(const BuildError& old)
	: msg(old.msg)
	{
	}

	BuildError::BuildError(const std::string& Msg)
	: msg(Msg)
	{
	}

	BuildError::~BuildError(void) noexcept
	{
	}

	const char* BuildError::what(void) const noexcept
	{
		return this->msg.c_str();
	}

	Node::Node(
		I_TYPE *part,
		const int NbPart,
		const int NbMin,
		std::initializer_list<double> center,
		const double size,
		const unsigned int level,
		Node<T> *parent
	)
	: level(level), cote(size), frere(NULL), fils(NULL), parent(parent), first(part), N(NbPart), Leaf(NbMin)
	{
		if( center.size() != 3 )
			throw BuildError("Center Coordinate must be in 3D space");

		int j = 0;
		for(auto i = center.begin() ; i != center.end() && j < 3 ; ++i, j++) {
			this->Pos[j] = *i;
		}
	}

	Node::Node(
		I_TYPE *part,
		const int NbPart,
		const int NbMin,
		const double center[3],
		const double size,
		const unsigned int level,
		Node *parent
	)
	: level(level), cote(size), frere(NULL), fils(NULL), parent(parent), first(part), N(NbPart), Leaf(NbMin)
	{
		for(auto i = 0; i < 3; i++) {
			this->Pos[i] = center[i];
		}
	}

	Node::Node(
		const Node &obj,
		Node *parent
	)
	: level(obj.level), cote(obj.cote), frere(NULL), fils(NULL), parent(parent), first(obj.first), N(obj.N), Level_Max(obj.Level_Max), NB_Bro(obj.NB_Bro), Leaf(obj.Leaf)
	{
		for(int i = 0; i<3; i++)
		{
			this->Pos[i] = obj.Pos[i];
		}

		if( obj.fils != NULL )
			this->fils = new Node(*obj.fils, this);
		if( obj.frere != NULL )
			this->frere = new Node(*obj.frere, this);
	}

	Node::Node(
		const Node &obj
	)
	: level(obj.level), cote(obj.cote), frere(NULL), fils(NULL), parent(NULL), first(obj.first), N(obj.N), Level_Max(obj.Level_Max), NB_Bro(obj.NB_Bro), Leaf(obj.Leaf)
	{
		for(int i = 0; i<3; i++)
		{
			this->Pos[i] = obj.Pos[i];
		}

		if( obj.fils != NULL )
			this->fils = new Node(*obj.fils, this);
		if( obj.frere != NULL )
			this->frere = new Node(*obj.frere, this);
	}

	bool Node::In(math::Point<F_TYPE>& point)
	{
		for(int i=0; i<3; i++) {
			if( point[i] <= this->Pos[i] - this->cote * 0.5
			    ||
			    point[i] >  this->Pos[i] + this->cote * 0.5
			  )
				return false;
		}

		return true;
	}

	std::string Node::GetError(void)
	{
		std::string tmp = this->error;
		this->error = "No Error.";
		return tmp;
	}

	int Node::GetDeep(void) const
	{
		if( this->fils == NULL )
			return this->level;

		int lvl = 0;
		for(auto t1=this->fils; t1 != NULL; t1 = t1->frere)
		{
			int tmp = t1->GetDeep();
			if( tmp > lvl )
				lvl = tmp;
		}
		return lvl;
	}

	Node* Node::Next(void)
	{
		return this->frere;
	}

	Node* Node::Up(void)
	{
		return this->parent;
	}

	Node* Node::Down(void)
	{
		return this->fils;
	}

	Node* Node::GetNodeOf(math::Point<F_TYPE>& part)
	{
		if( this->In(part) )
		{
			if( this->fils != NULL )
				return this->fils->GetNodeOf(part);
			else
				return this;
		}
		else
			if( this->frere != NULL )
				return this->frere->GetNodeOf(part);
		return NULL;
	}

	const double* Node::GetCenter(void) const
	{
		return (const double*)this->Pos;
	}

	int Node::GetN(void) const
	{
		return this->N;
	}

	int Node::GetLevel(void) const
	{
		return this->level;
	}

	double Node::GetSize(void) const
	{
		return this->cote;
	}

	bool Node::Build(void)
	{
		if( this->first == NULL || this->N == 0 )
		{
			this->error = "No Particule array set!";
			return false;
		}

		if( this->frere != NULL )
			delete this->frere;
		if( this->fils != NULL )
			delete this->fils;

		this->build_level();
		return true;
	}

	Node::~Node(void)
	{
		if( this->frere != NULL )
			delete this->frere;
		if( this->fils != NULL )
			delete this->fils;
	}
} /* tree */
