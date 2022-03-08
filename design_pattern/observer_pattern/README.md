[抽象观察者类]-AbstractObserver: 包含Update纯虚函数，收到订阅通知时，更新消息
[抽象订阅者类]-AbstractSubject: 包含Attach、Datch、Notify纯虚函数
[订阅者类]-Subject: 具体订阅者类（被观察者），实现Attach、Datch、Notify函数，绑定、解绑观察者，有观察消息时通知所有的观察者
[观察者类]-Observer: 具体观察者，主动订阅和解订阅"订阅者对象"，实现Subscirbe(调用Attach，绑定自己)、UnSubscirbe(调用Detach,解绑自己)、Update函数（收到订阅通知时，更新消息）

[适用场景]: 一对多场景，当订阅者状态改变时，通知所有订阅了它的观察者，并更新消息
[优点]: 一对多，观察者和被观察者建立了抽象的耦合
[缺点]: 观察者过多，通知效率低；被观察者循环依赖，循环调用，导致系统崩溃