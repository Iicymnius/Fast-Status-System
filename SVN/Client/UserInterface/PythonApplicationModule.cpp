//find;

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 0);
#endif

//add below;

#ifdef ENABLE_STATUS_UP_RENEWAL
	PyModule_AddIntConstant(poModule, "ENABLE_STATUS_UP_RENEWAL", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_STATUS_UP_RENEWAL", 0);
#endif