#include "TestfileControllerBuilder.hpp"


namespace Tester
{
  TestfileControllerBuilder::TestfileControllerBuilder( Collector::FileMVC * data )
  {
    this->data_ptr = data;
    this->value_generator = new Generator::ValueGenerator();
    this->testfile = new Tester::TestfileProduct();
  }

  void TestfileControllerBuilder::build_test_class()
  {
    std::stringstream stream;

    stream << "@TestFor(" << data_ptr->class_name << ")"
           << std::endl
           << "@Mock(" << data_ptr->model_base << ")"
           << std::endl
           << "class " << data_ptr->class_name << "Tests {"
           << std::endl
           << std::endl;

    this->testfile->set_test_class( stream.str() );
  }

  std::string TestfileControllerBuilder::build_package()
  {
    std::stringstream stream;

    stream << "package " << data_ptr->package
           << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_imports()
  {
    std::stringstream stream;

    stream << "import org.junit.*"
           << std::endl
           << "import grails.test.mixin.*"
           << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_valid_setup()
  {
    std::stringstream stream;

    stream << "  def populateValidParams(params) {"
           << std::endl
           << "    assert params != null"
           << std::endl
           << std::endl
           << create_params()
           << std::endl
           << "  }"
           <<std::endl
           << std::endl;

    return stream.str();
  }

  void TestfileControllerBuilder::build_valid_testcases()
  {
    const int qtd_methods = data_ptr->methods.size();
    std::stringstream stream;
    std::vector<std::string> testcases;

    testcases.push_back( build_valid_setup() );
    testcases.push_back( build_index() );

    for( int i = 0; i < qtd_methods; i++ )
    {
      if( data_ptr->methods[ i ].name == "create" )
      {
        testcases.push_back( build_create() );
      } else if( data_ptr->methods[ i ].name == "show" )
      {
        testcases.push_back( build_show() );
      } else if( data_ptr->methods[ i ].name == "delete" )
      {
        testcases.push_back( build_delete() );
      } else if( data_ptr->methods[ i ].name == "list" )
      {
        testcases.push_back( build_list() );
      } else if( data_ptr->methods[ i ].name == "save" )
      {
        testcases.push_back( build_save() );
      } else if( data_ptr->methods[ i ].name == "edit" )
      {
        testcases.push_back( build_edit() );
      } else if( data_ptr->methods[ i ].name == "update" )
      {
        testcases.push_back( build_update() );
      }
    }

    this->testfile->set_valid_testcases( testcases );
  }


  std::string TestfileControllerBuilder::build_index()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::stringstream stream;

    stream << " void testIndex() {"
           << std::endl
           << "    controller.index()"
           << std::endl
           << "    assert \"/" << low_domain
           << "/list\" == response.redirectedUrl"
           << std::endl
           << "  }"
           << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_create()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::stringstream stream;

    stream << "  void testCreate() {" << std::endl
           << "    def model = controller.create()" << std::endl
           << std::endl
           << "    assert model."<< low_domain << "Instance != null"
           << std::endl
           << "  }" << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_show()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::string up_domain = data_ptr->model_base;
    std::stringstream stream;

    stream << "  void testShow() {" << std::endl
           << "    controller.show()" << std::endl
           << "    assert flash.message != null" << std::endl
           << "    assert response.redirectedUrl == '/" << low_domain << "/list'"
           << std::endl
           << std::endl
           << "    populateValidParams(params)" << std::endl
           << "    def " << low_domain << " = new " << data_ptr->model_base
           << "(params)" << std::endl
           << std::endl
           << "    assert " << low_domain << ".save() != null" << std::endl
           << std::endl
           << "    params.id = " << low_domain << ".id" << std::endl
           << std::endl
           << "    def model = controller.show()" << std::endl
           << std::endl
           << "    assert model." << low_domain << "Instance == "
           << low_domain << std::endl
           << "  }" << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_delete()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::string up_domain = data_ptr->model_base;
    std::stringstream stream;

    stream << "  void testDelete() {" << std::endl
           << "    controller.delete()" << std::endl
           << "    assert flash.message != null" << std::endl
           << "    assert response.redirectedUrl == '/"
           << low_domain << "/list'" << std::endl
           << std::endl
           << "    response.reset()" << std::endl
           << std::endl
           << "    populateValidParams(params)" << std::endl
           << "    def " << low_domain << " = new " << up_domain << "(params)"
           << std::endl
           << std::endl
           << "    assert " << low_domain << ".save() != null" << std::endl
           << "    assert " << up_domain << ".count() == 1" << std::endl
           << std::endl
           << "    params.id = " << low_domain << ".id" << std::endl
           << std::endl
           << "    controller.delete()" << std::endl
           << std::endl
           << "    assert " << low_domain << ".count() == 0" << std::endl
           << "    assert " << low_domain << ".get(" << low_domain << ".id) == null"
           << std::endl
           << "    assert response.redirectedUrl == '/"
           << low_domain << "/list'" << std::endl
           << "  }" << std::endl
           << "}" << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_list()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::string up_domain = data_ptr->model_base;
    std::stringstream stream;

    stream << "  void testList() {" << std::endl
           << "    def model = controller.list()" << std::endl
           << std::endl
           << "    assert model." << low_domain << "InstanceList.size() == 0"
           << std::endl
           << "    assert model." << low_domain << "InstanceTotal == 0" << std::endl
           << "  }" << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_save()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::string up_domain = data_ptr->model_base;
    std::stringstream stream;

    stream << "  void testSave() {" << std::endl
           << "    controller.save()" << std::endl
           << std::endl
           << "    assert model." << low_domain
           << "Instance != null" << std::endl
           << "    assert view == '/" << low_domain << "/create'" << std::endl
           << std::endl
           << "    response.reset()" << std::endl
           << "" << std::endl
           << "    populateValidParams(params)" << std::endl
           << "    controller.save()" << std::endl
           << std::endl
           << "    assert response.redirectedUrl == '/"
           << low_domain << "/show/1'" << std::endl
           << "    assert controller.flash.message != null" << std::endl
           << "    assert " << up_domain << ".count() == 1" << std::endl
           << "  }" << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_edit()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::string up_domain = data_ptr->model_base;
    std::stringstream stream;

    stream << "  void testEdit() {" << std::endl
           << "    controller.edit()" << std::endl
           << std::endl
           << "    assert flash.message != null" << std::endl
           << "    assert response.redirectedUrl == '/"
           << low_domain << "/list'" << std::endl
           << std::endl
           << "    populateValidParams(params)" << std::endl
           << "    def " << low_domain << " = new " << up_domain << "(params)"
           << std::endl
           << std::endl
           << "    assert " << low_domain << ".save() != null" << std::endl
           << std::endl
           << "    params.id = " << low_domain << ".id" << std::endl
           << std::endl
           << "    def model = controller.edit()" << std::endl
           << std::endl
           << "    assert model." << low_domain << "Instance == "
           << low_domain << std::endl
           << "  }" << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileControllerBuilder::build_update()
  {
    std::string low_domain = Helper::convert_to_lower( data_ptr->model_base );
    std::string up_domain = data_ptr->model_base;
    std::stringstream stream;

    stream << "  void testUpdate() {" << std::endl
           << "    controller.update()" << std::endl
           << std::endl
           << "    assert flash.message != null" << std::endl
           << "    assert response.redirectedUrl == '/" << low_domain << "/list'"
           << std::endl
           << std::endl
           << "    response.reset()" << std::endl
           << std::endl
           << "    populateValidParams(params)" << std::endl
           << "    def " << low_domain << " = new " << up_domain << "(params)"
           << std::endl
           << std::endl
           << "    assert " << low_domain << ".save() != null" << std::endl
           << std::endl
           << "  }" << std::endl
           << std::endl;

    return stream.str();
  }

  void TestfileControllerBuilder::build_setup()
  {
    std::string setup( "\n" );
    this->testfile->set_setup( setup );
  }
}
