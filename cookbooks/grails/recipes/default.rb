# Install the package of the curl
#
execute "curl" do
  command "apt-get install curl"
end

# Install the package of the gvm
#
#execute "gvm" do
#  command "curl -s get.gvmtool.net | bash"
#end

# Install the package of the grails
#
#execute "grails" do
#  command "gvm install grails"
#end
