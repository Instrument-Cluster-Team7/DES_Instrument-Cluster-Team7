FROM junspring/team7-example-image:1.0

RUN apt-get update && apt-get install -y \
    qml-module-qtquick-controls \
    qml-module-qtquick-controls2 \
    qml-module-qtquick2 \
    qml-module-qtquick-window2\
    mesa-utils \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* 
