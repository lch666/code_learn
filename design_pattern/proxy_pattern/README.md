[抽象主题类]-ImageSubject: 抽象类声明具体主题类和代理类需要实现的业务方法
[具体主题类]-ImageReal: 实现抽象主题的类的方法，代理对象最终需要引用的对象
[代理类]-ProxyImage: 提供与具体主题相同的方法，引用具体主题类，可以访问、控制或者扩展真实主题类的功能

[适用场景] 为一个对象提供一种代理以控制对它的访问；代理对象为访问对象和目标对象的中介
[应用实例] 通过APP在线购买火车票，而不用直接去车站购买；文档中嵌入图形代理对象（真实对象开销大），点开图形时再打开图形，避免一次性创建开销大的对象(虚代理)
[优点] 客户端(访问对象)与目标对象解耦合（保护），并可以扩展目标对象的功能，代理对象起中介作用
[缺点] 增加系统设计中的类（代理对象），增加复杂度和响应速度