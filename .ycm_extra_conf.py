#!/usr/bin/env python3

import subprocess

import os



def GetStdFlags():
    flags = [
    '-Wall',
    '-Wextra',
    '-Wc++11-compat',
    '-Wno-long-long',
    '-Wno-variadic-macros',
    '-x', 'c++',
    '-fexceptions',
    '-DNDEBUG',
    '-std=c++11',
    #'-I','/opt/ROOT/include'
    ]
    return flags

def GetConfigParams(config):
    got  = subprocess.run(config.split(),stdout=subprocess.PIPE)
    rvalue = got.stdout.decode('utf-8').strip()
    made = rvalue.replace('-I','-I ').split()
    return made 


def FlagsForFile( filename, **kwargs ):
    config ="wx-config --cxxflags"
    flags = GetStdFlags() + GetConfigParams(config)
    rmap =  {
        'flags': flags,
        'do_cache': True
    }
    print(rmap)
    return rmap;

if __name__ == '__main__':
    FlagsForFile('basic.C')

