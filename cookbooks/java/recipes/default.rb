execute "sudo add-apt-repository ppa:webupd8team/java -y"

# could be improved to run only on update
execute "accept-license" do
  command "echo oracle-java8-installer shared/accepted-oracle-license-v1-1 select true | /usr/bin/debconf-set-selections"
end

execute "update" do
  command "apt-get update"
end

package "oracle-java8-installer" do
  action :install
end

package "oracle-java8-set-default" do
  action :install
end
