//
//  ScriptEngine.cpp
//  iTMP
//
//  Created by Ryan on 12-5-8.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#include "ScriptEngine.h"
#include "tolua++.h"


#pragma comment(lib,"libtolua++.a")
CScriptEngine::CScriptEngine(void)
{
	//Lua Initial
    m_pLuaState =luaL_newstate();
	luaL_openlibs(m_pLuaState);
	//open(m_pLuaState);
	//RegisterAll();
    tolua_open(m_pLuaState);
}

CScriptEngine::~CScriptEngine(void)
{
    printf("CScriptEngine::~CScriptEngine(void)\r\n");
	lua_close(m_pLuaState);
}

int CScriptEngine::Init()
{
	RegisterAll();
	return 0;
}

int CScriptEngine::LoadFile(const char *szFile)
{
    return luaL_loadfile(m_pLuaState, szFile);
}

int CScriptEngine::DoFile(const char * szFile)
{
    
	return luaL_dofile(m_pLuaState,szFile);
}

int CScriptEngine::DoString(const char * szText)
{
	return luaL_dostring(m_pLuaState,szText);
}

//const char* CScriptEngine::Pcall(lua_State* luastate,const char* szTable,const char* szFun,char* paramter,char* output)
//{
    //bool ret = false;
    
    //g_manualLua_mutex.lock();
//    strlen(<#const char *#>)
//    suboptarg
//    lua_getglobal(luastate, szTable);
//    lua_pushfstring(luastate,szFun);
//    lua_gettable(luastate,-2);
//    if(lua_isfunction(luastate,-1))
//    {
//        for (int i=0; i<len; i++)
//        {
//            switch (paramter[i])
//            {
//                case "string":
//                    lua_pushfstring(luastate,szFun);
//                    break;
//                case "bool":
//                    lua_pushboolean(luastate, <#int b#>);
//                    break;
//                case "long":
//                    lua_pushinteger(luastate, lua_Integer n);
//                    break;
//                case "number":
//                    lua_pushnumber(luastate, <#lua_Number n#>);
//                    break;
//                case "nil":
//                    lua_pushnil(luastate, lua_Integer n);
//                    break;
//                    
//                default:
//                    break;
//            }
//            
//        }
//        int err=lua_pcall(luastate, 0, 1, 0);
//        if(err==0)
//        {
//            ret = (bool)lua_toboolean(luastate, -1);
//            //g_manualLua_mutex.unlock();
//            return "call ok";
//        }
//        else
//        {
//            //g_manualLua_mutex.unlock();
//            return lua_tostring(luastate, -1);
//        }
//    }
//    else if (lua_isnil(luastate, -1))
//    {
//        //g_manualLua_mutex.unlock();
//        return "function is nil";
//    }
//    else
//    {
//        //g_manualLua_mutex.unlock();
//        return "function call fail";
//    }
//}

int CScriptEngine::LoadFile(lua_State* luaState,const char *szFile)
{
    return luaL_loadfile(luaState, szFile);
}

int CScriptEngine::DoFile(lua_State* luaState,const char * szFile)
{
    
	return luaL_dofile(luaState,szFile);
}

int CScriptEngine::DoString(lua_State* luaState,const char * szText)
{
	return luaL_dostring(luaState,szText);
}

void CScriptEngine::RegisterAll()
{
	
}

lua_State * CScriptEngine::GetLuaState() const
{
    return m_pLuaState;
}

void CScriptEngine::Reslease()
{
    
}
