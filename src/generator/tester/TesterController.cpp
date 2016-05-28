#include "TesterController.hpp"

namespace Tester
{
  TesterController::TesterController( Helper::Data * ptr_data )
  {
    this->set_data( ptr_data );
  }

  void TesterController::write_data()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      make_header( &test_stream );
      make_valid_setup( &test_stream );
      make_test_index( &test_stream );
      test_methods( &test_stream );
      TesterBase::conclude_data( &test_stream );

      test_stream.close();
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void TesterController::make_header( std::fstream * test_stream )
  {
    (* test_stream) << "package " << data_ptr->package_name
                    << std::endl
                    << std::endl
                    << "import org.junit.*"
                    << std::endl
                    << "import grails.test.mixin.*"
                    << std::endl
                    << std::endl
                    << "@TestFor(" << data_ptr->class_name << ")"
                    << std::endl
                    << "class " << data_ptr->class_name << "Tests {"
                    << std::endl
                    << std::endl;
  }

  void TesterController::make_valid_setup( std::fstream * test_stream )
  {
    (* test_stream) << "\tdef populateValidParams(params) {"
                    << std::endl
                    << "\t\tassert params != null"
                    << std::endl
                    << std::endl;

                    create_params( test_stream );

    (* test_stream) << std::endl
                    << "\t}"
                    <<std::endl
                    << std::endl;
  }

  void TesterController::create_params( std::fstream * test_stream )
  {
    for( int i = 0; i < data_ptr->proprieties.size(); i++ )
    {
      Helper::Propriety propriety = data_ptr->proprieties[ i ];

      if( propriety.name.compare( "dateCreated") &&
          propriety.name.compare( "lastUpdated") )
      {
        std::string value = create_value( propriety );

        (* test_stream) << "\t\tparams[\""
                        << propriety.name
                        << "\"] = "
                        << value
                        << std::endl;
      } else
      {
        // Nothing to do
      }
    }
  }

  std::string TesterController::create_value( Helper::Propriety propriety )
  {
    std::string value( "VALID VALUE" );
    std::string type = propriety.type;
    std::vector<Helper::Constraint> constraints = propriety.contraints;

    return value;
  }

  std::string TesterController::generate_randon_string( int size )
  {
    std::string random_string;
    static const std::string alphanum( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" );

    for( int i = 0; i < size; i++ )
    {
      random_string += alphanum[ rand() % ( alphanum.size()-1 ) ];
    }

    return random_string;
  }

  void TesterController::make_test_index( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );

    (* test_stream) << "\tvoid testIndex()"
                    << std::endl
                    << "\t\tcontroller.index()"
                    << std::endl
                    << "\t\tassert \"/" << low_domain  << "/list\" == response.redirectedUrl"
                    << std::endl
                    << "\t}"
                    << std::endl
                    << std::endl;
  }

  void TesterController::test_methods( std::fstream * test_stream )
  {
    if( (* test_stream).is_open() )
    {
      const int qtd_methods = data_ptr->methods.size();

      for( int i = 0; i < qtd_methods; i++ )
      {
        if( data_ptr->methods[ i ].name == "create" )
        {
          make_test_create( test_stream );
        } else if( data_ptr->methods[ i ].name == "show" )
        {
          make_test_show( test_stream );
        } else if( data_ptr->methods[ i ].name == "delete" )
        {
          make_test_delete( test_stream );
        } else if( data_ptr->methods[ i ].name == "list" )
        {
          make_test_list( test_stream );
        } else if( data_ptr->methods[ i ].name == "save" )
        {
          make_test_save( test_stream );
        } else if( data_ptr->methods[ i ].name == "edit" )
        {
          make_test_edit( test_stream );
        } else if( data_ptr->methods[ i ].name == "update" )
        {
          make_test_update( test_stream );
        }
      }
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void TesterController::make_test_create( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );

    (* test_stream) << "\tvoid testCreate() {" << std::endl
      << "\t\tdef model = controller.create()" << std::endl
      << std::endl
      << "\t\tassert model."<< low_domain << "Instance != null"
      << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_show( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testShow() {" << std::endl
      << "\t\tcontroller show" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/" << low_domain << "/list'"
      << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << data_ptr->domain_base
      << "(params)" << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << std::endl
      << "\t\tdef model = controller.show()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain << "Instance == "
      << low_domain << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_delete( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testDelete() {" << std::endl
      << "\t\tcontroller.delete()" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/list'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << up_domain << "(params)"
      << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << "\t\tassert " << up_domain << ".count() == 1" << std::endl
      << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << std::endl
      << "\t\tcontroller.delete()" << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".count() == 0" << std::endl
      << "\t\tassert " << low_domain << ".get(" << low_domain << ".id) == null"
      << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/list'" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_list( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testList() {" << std::endl
      << "\t\tdef model = controller.list()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain << "InstanceList.size() == 0"
      << std::endl
      << "\t\tassert model." << low_domain << "InstanceTotal == 0" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_save( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testSave() {" << std::endl
      << "\t\tcontroller.save()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain
      << "Instance != null" << std::endl
      << "\t\tassert view == '/" << low_domain << "/create'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << "" << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tcontroller.save()" << std::endl
      << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/show/1'" << std::endl
      << "\t\tassert controller.flash.message != null" << std::endl
      << "\t\tassert " << up_domain << ".count() == 1" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_edit( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testEdit() {" << std::endl
      << "\t\tcontroller.edit()" << std::endl
      << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/list'" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << up_domain << "(params)"
      << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << std::endl
      << "\t\tdef model = controller.edit()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain << "Instance == "
      << low_domain << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_update( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testUpdate() {" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/" << low_domain << "/list'"
      << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << up_domain << "(params)"
      << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << std::endl
      << "\t\t// test invalid parameters in update" << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << "\t\t//TODO: add invalid values to params object" << std::endl
      << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert view == \"/" << low_domain << "/edit\"" << std::endl
      << "\t\tassert model." << low_domain << "Instance != null" << std::endl
      << std::endl
      << "\t\tuser.clearErrors()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert response.redirectedUrl == \"/" << low_domain
      << "/show/$" << low_domain << ".id\"" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << "\t\t" << low_domain << ".clearErrors()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << "\t\tparams.version = -1" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert view == \"/" << low_domain << "/edit\"" << std::endl
      << "\t\tassert model." << low_domain << "Instance != null" << std::endl
      << "\t\tassert model." << low_domain
      << "Instance.errors.getFieldError('version')" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }
}
