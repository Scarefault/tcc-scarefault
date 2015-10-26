# Install the package of the curl
#
execute "curl" do
  command "apt-get install curl"
end

# Install the package of the gvm
#
execute "gvm" do
   command "curl -s get.sdkman.io | bash"
end

#bash "source gvm-init" do
#  cwd "/home/vagrant/.gvm/bin"
#  code "source gvm-init.sh"
#  action :run
#end

#execute "update for grails" do
#  command "apt-get update"
#end

# Install the package of the grails
#
#execute "grails" do
#  command "gvm install grails"
#end
