Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"

  config.vm.network :forwarded_port, guest: 8080, host: 2323
  config.vm.network :private_network, ip: "192.168.222.222"

  config.vm.provider "virtualbox" do |v|
    v.memory = 1536
    v.cpus = 2
  end

  # Fix error stdin no tty
  #
  config.vm.provision "fix-no-tty", type: "shell" do |shell|
    shell.privileged = false
    shell.inline = "sudo sed -i '/tty/!s/mesg n/tty -s \\&\\& mesg n/' /root/.profile"
  end

  config.vm.provision "shell", path: "scripts/scarefault.sh"
  config.vm.provision "shell", path: "scripts/gpp.sh"
  config.vm.provision "shell", path: "scripts/java.sh"

  config.vm.provision "shell", inline: "echo 'Installing: ( 1 ) sdkman and ( 2 ) grails'"

  config.vm.provision "install-sdkman", type: "shell" do |shell|
    shell.privileged = false
    shell.inline = "curl -s get.sdkman.io | bash"
  end
end
