xhost +local:docker

docker run \
    --rm \
    -e "DISPLAY=$DISPLAY" \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    qt5-bin-build:latest