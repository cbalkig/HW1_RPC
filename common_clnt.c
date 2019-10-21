/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "common.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

double *
add_1(argp, clnt)
	char **argp;
	CLIENT *clnt;
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, ADD, xdr_wrapstring, argp, xdr_double, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}

double *
subtract_1(argp, clnt)
	char **argp;
	CLIENT *clnt;
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, SUBTRACT, xdr_wrapstring, argp, xdr_double, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}

double *
multiply_1(argp, clnt)
	char **argp;
	CLIENT *clnt;
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, MULTIPLY, xdr_wrapstring, argp, xdr_double, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}

double *
divide_1(argp, clnt)
	char **argp;
	CLIENT *clnt;
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, DIVIDE, xdr_wrapstring, argp, xdr_double, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}