# Use the base image
FROM junspring/team7-example-image:latest

# Update package lists and install git
RUN apt-get update && apt-get install -y \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Clone the GitHub repository into the home directory
RUN git clone https://github.com/Instrument-Cluster-Team7/DES_Instrument-Cluster-Team7.git /DES_Instrument-Cluster-Team7

# Set the working directory
WORKDIR /DES_Instrument-Cluster-Team7

# Add any additional commands here if needed

