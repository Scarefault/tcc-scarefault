Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"

  # Fix error stdin no tty
  #
  config.vm.provision "fix-no-tty", type: "shell" do |shell|
    shell.privileged = false
    shell.inline = "sudo sed -i '/tty/!s/mesg n/tty -s \\&\\& mesg n/' /root/.profile"
  end

  # Setup the provisioner Chef-Solo
  #
  config.vm.provision "chef_solo" do |chef|
    chef.add_recipe "scarefault"
    chef.add_recipe "gpp"
    chef.add_recipe "java"
  end

  config.vm.provision "install-sdkman", type: "shell" do |shell|
    shell.privileged = false
    shell.inline = "curl -s get.sdkman.io | bash"
  end

  config.vm.provision "load sdkman-init", type: "shell" do |shell|
    shell.privileged = false
    shell.inline = "source '/home/vagrant/.sdkman/bin/sdkman-init.sh'"
  end
end
