// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * helloC.hpp
 * Copyright (C) Andrés Senac 2011 <andres@senac.es>
 *
 * idlyami is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * idlyami is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IDLYAMI_EXAMPLES_HELLO_HELLOC_HPP
#define IDLYAMI_EXAMPLES_HELLO_HELLOC_HPP

#include <idlyami/idlyami.hpp>

namespace MyModule
{

class MyInterface
{
protected:

    MyInterface();

public:

    virtual ~MyInterface();

    typedef idlyami::Operation < MyInterface,
                                 false,
                                 void,
                                 idlyami::Arg_IN< int >,
                                 idlyami::Arg_INOUT< int >,
                                 idlyami::Arg_OUT< int > > _my_operation_t;

    typedef idlyami::Operation < MyInterface,
                                 false,
                                 void,
                                 idlyami::Arg_IN< float >,
                                 idlyami::Arg_INOUT< float >,
                                 idlyami::Arg_OUT< float > > _my_second_operation_t;

    typedef idlyami::Operation < MyInterface,
                                 false,
                                 void,
                                 idlyami::Arg_IN< std::string >,
                                 idlyami::Arg_INOUT< std::string >,
                                 idlyami::Arg_OUT< std::string > > _my_third_operation_t;

    typedef idlyami::Operation < MyInterface,
                                 true,
                                 void,
                                 idlyami::Arg_IN< std::string >,
                                 idlyami::Arg_IN< int >,
                                 idlyami::Arg_IN< float > > _my_oneway_operation_t;

    virtual void my_operation(int a, int& b, int& c) = 0;
    virtual void my_second_operation(float a, float& b, float& c) = 0;
    virtual void my_third_operation(const std::string& a, std::string& b, std::string& c) = 0;

    virtual void my_oneway_operation(const std::string& a, int b, float c) = 0;
};

class MyInterface_c : public virtual idlyami::Object, public virtual MyInterface
{
public:

    MyInterface_c(idlyami::ORB* orb, const std::string& target_endpoint,
            const std::string& poa_id,
            const std::string& servant_id);

    virtual ~MyInterface_c();

    void my_operation(int a, int& b, int& c);
    void my_second_operation(float a, float& b, float& c);
    void my_third_operation(const std::string& a, std::string& b, std::string& c);

    void my_oneway_operation(const std::string& a, int b, float c);
};

class MyInterface_s : public idlyami::Servant, public virtual MyInterface
{
protected:

    MyInterface_s();

public:

    virtual ~MyInterface_s();
};

} // MyModule

class MyModule_MyInterface_i : public MyModule::MyInterface_s
{
public:

    void my_operation(int a, int& b, int& c);
    void my_second_operation(float a, float& b, float& c);
    void my_third_operation(const std::string& a, std::string& b, std::string& c);

    void my_oneway_operation(const std::string& a, int b, float c);
};

#endif // IDLYAMI_EXAMPLES_HELLO_HELLOC_HPP

