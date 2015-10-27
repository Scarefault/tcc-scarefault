# Install the package of the gvm
#
execute "gvm" do
   command "curl -s get.sdkman.io | bash"
end

execute "source '/home/vagrant/.sdkman/bin/sdkman-init.sh'"

#execute "update for grails" do
#  command "apt-get update"
#end

# Install the package of the grails
#
#execute "grails" do
#  command "gvm install grails"
#end
