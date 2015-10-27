# Recipe to create a environment of development
#   to the Scarefault Project
#

execute "update for scarefault" do
  command "apt-get update"
end

# Install the package of the unzip
#
execute "install unzip" do
  command "apt-get install unzip"
end

# Install the package of the curl
#
execute "curl" do
  command "apt-get install curl"
end
