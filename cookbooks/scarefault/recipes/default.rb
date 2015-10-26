# Recipe to create a environment of development
#   to the Scarefault Project
#

execute "update for scarefault" do
  command "apt-get update"
end

execute "install unzip" do
  command "apt-get install unzip"
end
