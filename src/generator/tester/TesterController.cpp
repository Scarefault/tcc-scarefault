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
    std::vector<Helper::Constraint> constraints = propriety.contraints;

    if( is_string( propriety ) )
    {
      value = create_string( propriety );
    } else if( is_integer( propriety ) )
    {
      value = "0";
    } else if( is_floating( propriety ) )
    {
      value = value_generator.generate_floating();
    } else if( is_boolean( propriety ) )
    {
      value = value_generator.generate_boolean();
    } else
    {
      // Nothing to do
    }

    return value;
  }

  std::string TesterController::create_string( Helper::Propriety propriety )
  {
    clear_boolean_constraints();

    int min = 3;
    int max = 12;

    for( int i = 0; i < propriety.contraints.size(); i++ )
    {
      Helper::Constraint constraint = propriety.contraints[ i ];

      for( int type = 0; type < type_constraint.size(); type++ )
      {
        if( !constraint.name.compare( type_constraint[ type ] ) )
        {
          std::string min_string;
          std::string max_string;
          int range_op_position;
          std::cout << "type: " << type << "\n";
          switch( type )
          {
            case BLANK:
              boolean_constraints[ BLANK ] = convert_to_bool( constraint.value );
              break;
            case CREDIT_CARD:
              boolean_constraints[ CREDIT_CARD ] = convert_to_bool( constraint.value );
              break;
            case EMAIL:
              boolean_constraints[ EMAIL ] = convert_to_bool( constraint.value );
              break;
            case NULLABLE:
              boolean_constraints[ NULLABLE ] = convert_to_bool( constraint.value );
              break;
            case SIZE:
              range_op_position = constraint.value.find( ".." );
              min_string = constraint.value.substr( 0, range_op_position );
              max_string = constraint.value.substr( range_op_position+2 );
              min = std::stoi( min_string );
              max = std::stoi( max_string );
              break;
            case URL:
              boolean_constraints[ URL ] = convert_to_bool( constraint.value );
              break;
          }
        }
      }
    }

    return value_generator.generate_string( boolean_constraints, min, max );
  }

  void TesterController::make_test_index( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );

    (* test_stream) << "\tvoid testIndex()"
                    << std::endl
                    << "\t\tcontroller.index()"
                    << std::endl
                    << "\t\tassert \"/" << low_domain
                    << "/list\" == response.redirectedUrl"
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

  bool TesterController::is_string( Helper::Propriety propriety )
  {
    bool is_string = false;

    if( !propriety.type.compare( "String" ) )
    {
      is_string = true;
    } else
    {
      // Nothing to do
    }

    return is_string;
  }

  bool TesterController::is_integer( Helper::Propriety propriety )
  {
    bool is_integer = false;

    if( !propriety.type.compare( "Integer" ) || !propriety.type.compare( "int" ) )
    {
      is_integer = true;
    } else
    {
      // Nothing to do
    }

    return is_integer;
  }

  bool TesterController::is_floating( Helper::Propriety propriety )
  {
    bool is_floating = false;

    if( !propriety.type.compare( "Double" ) || !propriety.type.compare( "double" ) ||
        !propriety.type.compare( "Float" ) || !propriety.type.compare( "float" ) )
    {
      is_floating = true;
    } else
    {
      // Nothing to do
    }

    return is_floating;
  }

  bool TesterController::is_boolean( Helper::Propriety propriety )
  {
    bool is_boolean = false;

    if( !propriety.type.compare( "boolean" ) )
    {
      is_boolean = true;
    } else
    {
      // Nothing to do
    }

    return is_boolean;
  }

  bool TesterController::convert_to_bool( std::string text )
  {
    return ( text == "true" ) ? true : false;
  }

  void TesterController::clear_boolean_constraints()
  {
    for( int i = 0; i < boolean_constraints.size(); i++ )
    {
      boolean_constraints[ i ] = false;
    }
  }
}
