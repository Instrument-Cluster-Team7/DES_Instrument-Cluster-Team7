FROM balenalib/raspberrypi4-64-debian:latest

RUN apt-get update && apt-get install -y \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Clone the GitHub repository into the home directory
RUN git clone https://github.com/Instrument-Cluster-Team7/DES_Instrument-Cluster-Team7.git /DES_Instrument-Cluster-Team7

# Set the working directory
WORKDIR /DES_Instrument-Cluster-Team7
