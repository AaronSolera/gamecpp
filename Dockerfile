FROM alpine:latest

RUN apk add qt5-qtbase-dev \
            qt5-qtdeclarative-dev \
            qt5-qttools-dev \
            qt5-qtwayland-dev \
            qt5-qtscript-dev \
		    qt5-qtimageformats \
		    qt5-qttranslations \
		    qt5-qtgraphicaleffects \
            qt5-qtx11extras \
            g++ \
            make

# Set environment variables for Qt
ENV QT_X11_NO_MITSHM=1
ENV PATH=/usr/lib/qt5/bin:$PATH

COPY gamecpp/ /src
RUN mkdir /build

WORKDIR /build

RUN qmake /src/gamecpp.pro && make

ENTRYPOINT [ "./gamecpp" ]