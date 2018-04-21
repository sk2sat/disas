#include <iostream>
#include <fstream>
#include <string_view>
#include <array>

namespace sksat {
	enum class operand {
		none,
		imm8,
		imm,
		a,
		r8,
		r,
		rm8,
		rm,
		es,
	};

	struct insn {
		std::string_view opname;
		operand op1, op2;
	};

	constexpr std::array<insn, 256> ilist = {
#define INSN(name, op1, op2) #name, operand::op1, operand::op2
/*0x00*/	INSN(add, rm8,r8),
/*0x01*/	INSN(add, rm, r),
/*0x02*/	INSN(add, r8, rm8),
/*0x03*/	INSN(add, r,  rm),
/*0x04*/	INSN(add, a,  imm8),
/*0x05*/	INSN(add, a,  imm),
/*0x06*/	INSN(push, es, none),
/*0x07*/	INSN(pop,  es, none),
/*0x08*/	INSN(or, rm8, r8),
/*0x09*/	INSN(or, rm,  r),
/*0x0a*/	INSN(or, r8, rm8),
/*0x0b*/	INSN(or, r,  rm),
/*0x0c*/	INSN(or, a,  imm8),
/*0x0d*/	INSN(or, a,  imm),
#undef INSN
	};
}

int main(int argc, char **argv){
	if(argc!=2) return -1;
	std::ifstream binfile(argv[1], std::ios::binary);

	if(!binfile){
		std::cout<<"cannot open file."<<std::endl;
		return -1;
	}

	for(size_t i=0;i<sksat::ilist.size();i++){
		std::cout
			<< "0x" << std::hex << i
			<< ": "
			<< sksat::ilist[i].opname
			<< std::endl;
	}
}
