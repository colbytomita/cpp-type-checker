#include "AST.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//this part is the functions for creating the tree

void ASTProgram::addFunction(ASTFunction* theFunction)
{
	functions.push_back(theFunction);
}

void ASTFunction::setName(string name_in)
{
	name = name_in;
}

void ASTFunction::setParam(ASTParam* theParam)
{
	params = theParam;
}

void ASTFunction::setStatements(ASTNode* stmts)
{
	this->stmts = stmts;
}

void ASTParam::addParam(string type, string name)
{
	types.push_back(type);
	names.push_back(name);
}

void ASTStatements::addStatement(ASTNode* statement)
{
	statements.push_back(statement);
}

void ASTStatement::setStatement(ASTNode* statementin)
{
	statement = statementin;
}

ASTNode* ASTStatement::getStatement()
{
	return statement;
}

void ASTArgs::addArg(ASTNode* statement)
{
	args.push_back(statement);
}

void ASTWhile::setStatement(ASTNode* statementin)
{
	statement = statementin;
}

void ASTWhile::setCondition(ASTNode* statementin)
{
	condition = statementin;
}

void ASTIf::setStatement(ASTNode* statementin)
{
	statement = statementin;
}

void ASTIf::setCondition(ASTNode* statementin)
{
	condition = statementin;
}



void ASTAssign::setLHS(string in)
{
	lhs = in;
}

void ASTAssign::setRHS(ASTNode* statementin)
{
	rhs = statementin;
}

void ASTFunctionCall::setName(string in)
{
	lhs = in;
}

void ASTFunctionCall::setParam(ASTNode* statementin)
{
	params = statementin;
}

void ASTBlockStatement::setStatement(ASTNode* statementin)
{
	statement = statementin;
}

ASTDeclaration::ASTDeclaration()
{
	val = 0;
}

void ASTDeclaration::setName(string in)
{
	name = in;
}

void ASTDeclaration::setType(string in)
{

	type = in;
}

void ASTDeclaration::setVal(ASTNode* in)
{
	val = in;
}

void ASTBooleanExprA::addOperand(ASTNode* in)
{
	operands.push_back(in);
}

void ASTBooleanExprA::addOperator(string in)
{
	operators.push_back(in);
}

void ASTBooleanExprB::addOperand(ASTNode* in)
{
	operands.push_back(in);
}

void ASTBooleanExprB::addOperator(string in)
{
	operators.push_back(in);
}


void ASTTerm::addOperand(ASTNode* in)
{
	operands.push_back(in);
}

void ASTTerm::addOperator(string in)
{
	operators.push_back(in);
}


void ASTExpr::addOperand(ASTNode* in)
{
	operands.push_back(in);
}

void ASTExpr::addOperator(string in)
{
	operators.push_back(in);
}

ASTFactor::ASTFactor()
{
	element = 0;
	boolExpr = 0;
}

void ASTFactor::setBoolExpr(ASTNode* in)
{
	boolExpr = in;
}

void ASTFactor::setElement(ASTNode* in)
{
	element = in;
}

void ASTElement::setElement(string valuein, bool isFloatin)
{
	isFloat = isFloatin;
	value = valuein;
}

ASTParam* ASTFunction::getParams()
{
	return params;
}

vector<string> ASTParam::getNames()
{
	return names;
}

vector<string> ASTParam::getTypes()
{
	return types;
}

string ASTFunction::getName()
{
	return name;
}



//this part is the functions for printing the tree
void ASTProgram::print(int depth)
{
	for (int i = 0; i < functions.size(); i++)
	{
		functions[i]->print(0);

		if (i != functions.size() - 1)
			cout << "\n";
	}
}

void ASTFunction::print(int depth)
{
	cout << name << "(";
	params->print(0);
	cout << ")\n";
	cout << "{\n";
	stmts->print(depth + 1);
	cout << "}\n";
}


void ASTParam::print(int depth)
{
	for (int i = 0; i < names.size(); i++)
	{
		cout << types[i] << " " << names[i];
		if (i != names.size() - 1)
		{
			cout << ", ";
		}
	}
}

void ASTStatements::print(int depth)
{
	for (int i = 0; i < statements.size(); i++)
	{
		statements[i]->print(depth);
	}
}

void ASTStatement::print(int depth)
{
	statement->print(depth);
}

void ASTArgs::print(int depth)
{
	for (int i = 0; i < args.size(); i++)
	{
		args[i]->print(depth);
		if (i != args.size() - 1)
			cout << ", ";
	}
}

void ASTWhile::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}

	cout << "while(";
	condition->print(depth);
	cout << ")\n";

	ASTStatement* stmt = (ASTStatement*)statement;

	if (typeid(*(stmt->getStatement())) == typeid(ASTBlockStatement))
	{
		statement->print(depth);
	}
	else
	{
		statement->print(depth + 1);
	}
}

void ASTIf::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}

	cout << "if(";
	condition->print(depth);
	cout << ")\n";


	ASTStatement* stmt = (ASTStatement*)statement;

	if (typeid(*(stmt->getStatement())) == typeid(ASTBlockStatement))
	{
		statement->print(depth);
	}
	else
	{
		statement->print(depth + 1);
	}



}

void ASTAssign::print(int depth)
{


	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}

	cout << lhs << " = ";
	rhs->print(depth);
	cout << ";\n";
}

void ASTFunctionCall::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}

	cout << lhs << "(";
	params->print(depth);
	cout << ");\n";
}

void ASTBlockStatement::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}

	cout << "{\n";
	statement->print(depth + 1);

	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}
	cout << "}\n";
}

void ASTDeclaration::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}

	cout << type << " " << name;

	if (val != NULL)
	{
		cout << " = ";
		val->print(depth);
	}

	cout << ";\n";
}

void ASTBooleanExprA::print(int depth)
{

	operands[0]->print(depth);
	for (int i = 1; i < operands.size(); i++)
	{
		cout << " " << operators[i - 1] << " ";
		operands[i]->print(depth);
	}
}

void ASTBooleanExprB::print(int depth)
{

	operands[0]->print(depth);
	for (int i = 1; i < operands.size(); i++)
	{
		cout << " " << operators[i - 1] << " ";
		operands[i]->print(depth);
	}
}


void ASTTerm::print(int depth)
{

	operands[0]->print(depth);
	for (int i = 1; i < operands.size(); i++)
	{
		cout << " " << operators[i - 1] << " ";
		operands[i]->print(depth);
	}
}


void ASTExpr::print(int depth)
{

	operands[0]->print(depth);
	for (int i = 1; i < operands.size(); i++)
	{
		cout << " " << operators[i - 1] << " ";
		operands[i]->print(depth);
	}
}

void ASTFactor::print(int depth)
{
	if (boolExpr == 0)
	{
		element->print(depth);
	}
	else
	{
		cout << "(";
		boolExpr->print(depth);
		cout << ")";
	}
}

void ASTElement::print(int depth)
{
	cout << value;
}



void typeError(string code, int line, string message, bool& hasError)
{
	if (!hasError)
	{
		cout << code << " around line: " << line << " ;;; " << message << "\n";
		hasError = true;
	}
}

string typeToString(Type t)
{
	if (t == NULL_T)
		return "Null_Type";
	if (t == ERROR_T)
		return "Error_Type";
	if (t == FLOAT_T)
		return "Float_Type";
	if (t == BOOL_T)
		return "Bool_Type";

	return "Unknown type";
}

//ths function only
Type ASTFunction::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	stmts->typeCheck(map, fmap, hadError);
	return Type::NULL_T;
}

//this function should return null_t but must check the types of the various peices
Type ASTProgram::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	fmap = new FunctionParamMap();
	vector<string> keywords = {"if", "while", "float", "bool", "TRUE", "FALSE"};

	for (int i = 0; i < functions.size(); i++)
	{
		//create map
		TypeMap* m = new TypeMap();

		//add the params in
		ASTParam* params = functions[i]->getParams();

		vector<Type> functionParamTypes;

		//check param types and then add the types into the map.
		for (int j = 0; j < params->getNames().size(); j++)
		{
			vector<string> names = params->getNames();
			vector<string> types = params->getTypes();

			if (types[j] == "float")
			{
				string name = names[j];
				// check if name is a keyword
				if (find(keywords.begin(), keywords.end(), name) != keywords.end())
				{
					bool hadErrorB = false;
					typeError("T_Function06", functions[i]->getLine(), "Variable \"" + name + "\" is a keyword", hadError);
					hadError = hadError || hadErrorB;
				}
				//please note the weird syntax here, calling the [] operator as if it is the function.
				else if (m->operator[](names[j]) == NULL_T) //in this case null_t is 0 so that is what will be returned if it is empty.
				{
					//we good since it is not prev defined!
					m->operator[](names[j]) = FLOAT_T;
					functionParamTypes.push_back(FLOAT_T);
				}
				else
				{
					//already defined...
					typeError("T_Function01", getLine(), "Variable \"" + names[j] + "\" is already defined", hadError);
				}
			}
			else if (types[j] == "bool")
			{
				string name = names[j];
				// check if name is a keyword
				if (find(keywords.begin(), keywords.end(), name) != keywords.end())
				{
					bool hadErrorB = false;
					typeError("T_Function06", functions[i]->getLine(), "Variable \"" + name + "\" is a keyword", hadError);
					hadError = hadError || hadErrorB;
				}
				//please note the weird syntax here, calling the [] operator as if it is the function.
				else if (m->operator[](names[j]) == NULL_T) //in this case null_t is 0 so that is what will be returned if it is empty.
				{
					//we good since it is not prev defined!
					m->operator[](names[j]) = BOOL_T;
					functionParamTypes.push_back(BOOL_T);
				}
				else
				{
					//already defined...
					typeError("T_Function02", getLine(), "Variable \"" + names[j] + "\" is already defined", hadError);
				}
			}
			else
			{
				typeError("T_Function03", getLine(), "Type \"" + types[j] + "\" undefined", hadError);
			}
		}

		string name = functions[i]->getName();
		if(fmap->find(functions[i]->getName()) != fmap->end()){
			// throw an error for an already defined function name
			bool hadErrorB = false;
			typeError("T_function05", functions[i]->getLine(), "Function \"" + name + "\" is already defined", hadError);
			hadError = hadError || hadErrorB;
		}
		else if (name == "if" || name == "while" || name == "float" || name == "bool" || name == "TRUE" || name == "FALSE")
		{
			bool hadErrorB = false;
			typeError("T_function04", getLine(), "\"" + name + "\" keyword cannot be used as a function name", hadErrorB);
			hadError = hadError || hadErrorB;
		}
		else
		{
			//this means it uses the C rules that a function has to be defined before it can be called;
			fmap->operator[](functions[i]->getName()) = functionParamTypes;
		}



		//check the types
		functions[i]->typeCheck(m, fmap, hadError);
	}


	return Type::NULL_T;
}


Type ASTStatements::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	
	return Type::NULL_T;
}


Type ASTStatement::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}


Type ASTElement::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	
	return Type::NULL_T;
}


Type ASTDeclaration::typeCheck(TypeMap* m, FunctionParamMap* fmap, bool& hadError)
{
	
	return Type::NULL_T;
}


Type ASTFactor::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}



//these are for part 2


Type ASTWhile::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}
Type ASTIf::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}
Type ASTAssign::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}
Type ASTFunctionCall::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}
Type ASTBlockStatement::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}

//i had to implement this version of these to make factor and element work. This version must be corrected part 2
Type ASTBooleanExprA::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return operands[0]->typeCheck(map, fmap, hadError);
}
Type ASTBooleanExprB::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return operands[0]->typeCheck(map, fmap, hadError);
}
Type ASTTerm::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return operands[0]->typeCheck(map, fmap, hadError);
}
Type ASTExpr::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return operands[0]->typeCheck(map, fmap, hadError);
}



//this should be unused and handled in functioncall (i.e., function call should check the args itself)
Type ASTArgs::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}
//this function is unused and handled in function (that is, the function declaration)
Type ASTParam::typeCheck(TypeMap* map, FunctionParamMap* fmap, bool& hadError)
{
	return Type::NULL_T;
}



//this part is for outputting the bytecode