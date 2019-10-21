program RPC_CALCULATOR_PROG {
	version RPC_CALCULATOR_VERS {
		double ADD(string) = 1;
		double SUBTRACT(string) = 2;
		double MULTIPLY(string) = 3;
		double DIVIDE(string) = 4;
	} = 1;
} = 0x20000099;