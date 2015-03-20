# idlyami
A lightweight object-oriented middleware based on YAMI4

Description
idlyami is a lightweight object-oriented middleware, with a simple API, that uses YAMI4 as underlying transport.

idlyami will generate stubs and skeletons from IDL files.

The aim of idlyami is to provide a simple middleware with a mapping from IDL to C++ simpler than CORBA.

How to build idlyami
1. Download the source code from the repository. Details here

2. Download YAMI4 from http://www.inspirel.com/yami4/

3. Compile YAMI4 with -fPIC

4. Modify CMakeLists.txt with the correct path to YAMI4.

5. Compile idlyami:

idlyami$ mkdir build
idlyami$ cd build
build$ cmake ..
build$ make
IDL Compiler
We are developing the IDLYAMI IDL compiler with Eclipse Modeling Framework and their IDL support available from the idl4emf project (http://code.google.com/p/idl4emf/).

Our compiler is the EMF/Xpand project biz.senac.idlyami (at the repository) that requires the projects org.csu.idl.idlmm and org.csu.idl.xtext from idl4emf.
