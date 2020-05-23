# qml-cpp-binding
qml cpp binding example

Qt version 5.9.7

1. Passing CPP class object to QML by
    ```// Passing class object to QML
    engine.rootContext()->setContextProperty("TimeUpdate", &objTime);```

2. By connecting QML Slot to CPP Signal
    ```// Connect QML Signal to C++ Slot
    QObject::connect(rootObj->findChild<QObject*>("ButtonStart"), SIGNAL(startTimer()), &objTime, SLOT(startTimer()));```

3. Invoking QML method/slot from CPP
   ``` // Calling QML function from C++
    QMetaObject::invokeMethod(rootObj, "myQmlFunction", Q_ARG(QVariant, QDateTime::currentDateTime()));```
