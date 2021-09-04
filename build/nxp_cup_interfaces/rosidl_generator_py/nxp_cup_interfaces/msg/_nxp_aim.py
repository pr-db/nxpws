# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nxp_cup_interfaces:msg/NxpAim.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NxpAim(type):
    """Metaclass of message 'NxpAim'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nxp_cup_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nxp_cup_interfaces.msg.NxpAim')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nxp_aim
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nxp_aim
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nxp_aim
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nxp_aim
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nxp_aim

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NxpAim(metaclass=Metaclass_NxpAim):
    """Message class 'NxpAim'."""

    __slots__ = [
        '_timestamp',
        '_eagle_stop',
        '_eagle_left',
        '_eagle_right',
        '_eagle_straight',
        '_eagle_green',
        '_eagle_red',
    ]

    _fields_and_field_types = {
        'timestamp': 'uint64',
        'eagle_stop': 'uint8',
        'eagle_left': 'uint8',
        'eagle_right': 'uint8',
        'eagle_straight': 'uint8',
        'eagle_green': 'uint8',
        'eagle_red': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.timestamp = kwargs.get('timestamp', int())
        self.eagle_stop = kwargs.get('eagle_stop', int())
        self.eagle_left = kwargs.get('eagle_left', int())
        self.eagle_right = kwargs.get('eagle_right', int())
        self.eagle_straight = kwargs.get('eagle_straight', int())
        self.eagle_green = kwargs.get('eagle_green', int())
        self.eagle_red = kwargs.get('eagle_red', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.eagle_stop != other.eagle_stop:
            return False
        if self.eagle_left != other.eagle_left:
            return False
        if self.eagle_right != other.eagle_right:
            return False
        if self.eagle_straight != other.eagle_straight:
            return False
        if self.eagle_green != other.eagle_green:
            return False
        if self.eagle_red != other.eagle_red:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'timestamp' field must be an unsigned integer in [0, 18446744073709551615]"
        self._timestamp = value

    @property
    def eagle_stop(self):
        """Message field 'eagle_stop'."""
        return self._eagle_stop

    @eagle_stop.setter
    def eagle_stop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'eagle_stop' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'eagle_stop' field must be an unsigned integer in [0, 255]"
        self._eagle_stop = value

    @property
    def eagle_left(self):
        """Message field 'eagle_left'."""
        return self._eagle_left

    @eagle_left.setter
    def eagle_left(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'eagle_left' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'eagle_left' field must be an unsigned integer in [0, 255]"
        self._eagle_left = value

    @property
    def eagle_right(self):
        """Message field 'eagle_right'."""
        return self._eagle_right

    @eagle_right.setter
    def eagle_right(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'eagle_right' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'eagle_right' field must be an unsigned integer in [0, 255]"
        self._eagle_right = value

    @property
    def eagle_straight(self):
        """Message field 'eagle_straight'."""
        return self._eagle_straight

    @eagle_straight.setter
    def eagle_straight(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'eagle_straight' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'eagle_straight' field must be an unsigned integer in [0, 255]"
        self._eagle_straight = value

    @property
    def eagle_green(self):
        """Message field 'eagle_green'."""
        return self._eagle_green

    @eagle_green.setter
    def eagle_green(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'eagle_green' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'eagle_green' field must be an unsigned integer in [0, 255]"
        self._eagle_green = value

    @property
    def eagle_red(self):
        """Message field 'eagle_red'."""
        return self._eagle_red

    @eagle_red.setter
    def eagle_red(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'eagle_red' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'eagle_red' field must be an unsigned integer in [0, 255]"
        self._eagle_red = value
