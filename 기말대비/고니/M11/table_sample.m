function varargout = table_sample(varargin)
% TABLE_SAMPLE MATLAB code for table_sample.fig
%      TABLE_SAMPLE, by itself, creates a new TABLE_SAMPLE or raises the existing
%      singleton*.
%
%      H = TABLE_SAMPLE returns the handle to a new TABLE_SAMPLE or the handle to
%      the existing singleton*.
%
%      TABLE_SAMPLE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TABLE_SAMPLE.M with the given input arguments.
%
%      TABLE_SAMPLE('Property','Value',...) creates a new TABLE_SAMPLE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before table_sample_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to table_sample_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help table_sample

% Last Modified by GUIDE v2.5 09-May-2016 23:22:53

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @table_sample_OpeningFcn, ...
                   'gui_OutputFcn',  @table_sample_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before table_sample is made visible.
function table_sample_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to table_sample (see VARARGIN)

% Choose default command line output for table_sample
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes table_sample wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = table_sample_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes when entered data in editable cell(s) in uitable1.
function uitable1_CellEditCallback(hObject, eventdata, handles)
% hObject    handle to uitable1 (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.TABLE)
%	Indices: row and column indices of the cell(s) edited
%	PreviousData: previous data for the cell(s) edited
%	EditData: string(s) entered by the user
%	NewData: EditData or its converted form set on the Data property. Empty if Data was not changed
%	Error: error string when failed to convert EditData to appropriate value for Data
% handles    structure with handles and user data (see GUIDATA)
Idx = eventdata.Indices;
Val = str2num(eventdata.EditData);
fprintf('v(%d,%d) = %f\n', Idx(1), Idx(2), Val );

