Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"

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

  #config.vm.provision "load sdkman-init", type: "shell" do |shell|
  #  shell.privileged = false
  #  shell.inline = "sudo source '/home/vagrant/.sdkman/bin/sdkman-init.sh'"
  #end
end
