cmake_minimum_required(VERSION 3.24)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(DesignPatterns
        main.cpp
        TemplateMethodPattern/TemplateMethodPattern.h
        TemplateMethodPattern/TemplateMethodPattern.cpp
        FactoryMethodPattern/FactoryMethodPattern.cpp
        FactoryMethodPattern/FactoryMethodPattern.h
        AbstractFactoryMethodPattern/AbstractFactoryMethodPattern.cpp
        AbstractFactoryMethodPattern/AbstractFactoryMethodPattern.h
        AbstractFactoryMethodPatternOther/AbstractFactoryMethodPatternOther.cpp AbstractFactoryMethodPatternOther/AbstractFactoryMethodPatternOther.h
        BuilderPattern/BuilderPattern.cpp
        BuilderPattern/BuilderPattern.h
#        StrategyPattern/StrategyPattern.h
#        StrategyPattern/StrategyPattern.cpp
#        ObserverPattern/ObserverPattern.h ObserverPattern/ObserverPattern.cpp
        IteratorPattern/IteratorPattern.h IteratorPattern/IteratorPattern.tpp IteratorPatternOther/IteratorPatternOther.h IteratorPatternOther/IteratorPatternOther.tpp CompositePattern/CompositePattern.cpp CompositePattern/CompositePattern.h CompositePatternOther/CompositePatternOther.h CompositePatternOther/CompositePatternOther.cpp StatePattern/StatePattern.cpp StatePattern/StatePattern.h StatePatternOther/StatePatternOther.cpp StatePatternOther/StatePatternOther.h FlyWeightPattern/FlyWeightPattern.h FlyWeightPattern/FlyWeightPattern.cpp FlyWeightPatternOther/FlyWeightPatternOther.h FlyWeightPatternOther/FlyWeightPatternOther.cpp ProxyPattern/ProxyPattern.h ProxyPattern/ProxyPattern.cpp)
