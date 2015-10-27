execute "add java repository" do
  command "add-apt-repository ppa:webupd8team/java -y"
end

# could be improved to run only on update
execute "accept-license" do
  command "echo oracle-java8-installer shared/accepted-oracle-license-v1-1 select true | /usr/bin/debconf-set-selections"
end

execute "update for java" do
  command "apt-get update"
end

package "oracle-java8-installer" do
  action :install
end

#execute "sudo apt-get install oracle-java8-installer -y"

package "oracle-java8-set-default" do
  action :install
end
