#define PY_SSIZE_T_CLEAN

#include </usr/include/python3.6m/Python.h>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]){
	PyObject *pName, *pModule, *pDict,  *pFunc, *presult, *pValue;
//	wchar_t *program = Py_DecodeLocale(argv[0], NULL);

//	if (program == NULL){
//		fprintf(stderr, "Fatal error");
//		exit(1);
//	}

//	Py_SetProgramName(program);

	Py_Initialize();

	pName = PyUnicode_FromString((char*)"arbName");
	pModule = PyImport_Import(pName);
	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, (char*)"someFunction");

	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", (char*)"something");
		presult=PyObject_CallObject(pFunc,pValue);
	}
	cout << PyLong_AsLong(presult) << endl;
	Py_DECREF(pValue);
	Py_DECREF(pModule);
	Py_DECREF(pName);
//	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)"Greg"));
//	pValue = PyObject_CallObject(pFunc, pArgs);
//	auto result = _PyUnicode_AsString(pValue);
//	cout << result << endl;


//	PyRun_SimpleString("print('hello world')");

//	if (Py_FinalizeEx() < 0){
//		exit(120);
//	}
//	PyMem_RawFree(program);
	Py_Finalize();
	return 0;
}
