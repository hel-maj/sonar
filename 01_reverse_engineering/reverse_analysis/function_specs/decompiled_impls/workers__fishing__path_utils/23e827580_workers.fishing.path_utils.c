/* ===== 23e827580 workers.fishing.path_utils:68 ===== */
/* ghidra_name=FUN_23e827580 entry=23e827580 size=1947 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e827580(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  char cVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  undefined4 uVar20;
  undefined8 in_stack_fffffffffffffec0;
  undefined8 in_stack_fffffffffffffec8;
  uint uVar22;
  ulonglong uVar21;
  undefined8 in_stack_fffffffffffffed0;
  uint uVar24;
  ulonglong uVar23;
  undefined8 in_stack_fffffffffffffed8;
  uint uVar25;
  undefined8 in_stack_fffffffffffffee0;
  uint uVar27;
  ulonglong uVar26;
  undefined8 uStack_110;
  longlong lStack_108;
  code *pcStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong lStack_c8;
  undefined8 *puStack_c0;
  longlong *plStack_b8;
  undefined8 *puStack_b0;
  longlong *plStack_78;
  undefined8 uStack_70;
  undefined1 auStack_68 [16];
  longlong *plStack_58;
  
  plVar8 = _DAT_23eede738;
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);
  uVar25 = (uint)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
  uVar27 = (uint)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
  uVar22 = (uint)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  uVar24 = (uint)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  plStack_58 = (longlong *)0x0;
  auStack_68 = (undefined1  [16])0x0;
  if (_DAT_23eede738 == (longlong *)0x0) {
LAB_23e8275ca:
    _DAT_23eede738 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede730,DAT_23eede778,8);
  }
  else {
    lVar7 = *_DAT_23eede738;
    if (1 < lVar7) {
      *_DAT_23eede738 = lVar7 + -1;
      goto LAB_23e8275ca;
    }
    if (_DAT_23eede738[2] != 0) {
      *_DAT_23eede738 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e8275ca;
    }
  }
  plVar16 = _DAT_23eede738;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eede738 + 9;
  lVar15 = *(longlong *)(lVar7 + 8);
  _DAT_23eede738[0xf] = lVar15;
  *(longlong **)(lVar7 + 8) = plVar8;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar16[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar16[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar16 = *plVar16 + 1;
  *(undefined4 *)(plVar16 + 8) = 0;
  lVar7 = FUN_23e8dc1d0();
  if (lVar7 == 0) {
    uVar20 = 0x46;
    FUN_23e915740(param_1,auStack_68,DAT_23eedd020);
    plVar9 = (longlong *)0x0;
    plVar11 = DAT_23ed6a4f8;
    plVar8 = plStack_58;
    goto joined_r0x00023e8278dc;
  }
  *(undefined4 *)(plVar16 + 5) = 0x46;
  plVar8 = (longlong *)FUN_23e91a870(param_1,lVar7);
  if (plVar8 == (longlong *)0x0) {
    auStack_68 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x46;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e8278dc;
  }
  plVar9 = (longlong *)FUN_23e8c6f80(plVar8,_DAT_23eedd050);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (plVar9 == (longlong *)0x0) {
    auStack_68 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    uVar20 = 0x46;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e8278dc;
  }
  *(undefined4 *)(plVar16 + 5) = 0x48;
  plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23ed6cee0);
  if (plVar8 != (longlong *)0x0) {
    iVar6 = FUN_23a35f020(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = _DAT_23eedd058;
    if (iVar6 != -1) {
      if (iVar6 != 0) {
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar7 + 0x28);
        plVar16 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar16 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        lVar7 = *plVar9;
        plVar8[0xf] = 0;
        if (lVar7 != 0) {
          return plVar9;
        }
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        return plVar9;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar12 = *(longlong **)(lVar7 + 0xe20);
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar15 = plVar12[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar15;
        *plVar12 = 1;
      }
      pcVar3 = _PyRuntime_exref;
      plVar12[4] = 0;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar3 + 0x1f8) + 0x10) + 0x2e8);
      lVar15 = plVar12[-1];
      puVar19 = *(undefined8 **)(lVar7 + 8);
      *puVar19 = plVar12 + -2;
      plVar12[-2] = lVar7;
      plVar12[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar19;
      *(longlong **)(lVar7 + 8) = plVar12 + -2;
      *plVar8 = *plVar8 + 1;
      plVar12[3] = (longlong)plVar8;
      uVar10 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar8 == (longlong *)0x0) {
          PyErr_PrintEx(0);
          lVar7 = 1;
          Py_Exit();
          puStack_b0 = &DAT_23ed6cce0;
          puStack_c0 = &DAT_23ed6a4c0;
          DAT_23eedcfd0 = plVar8[2];
          DAT_23eede778 = plVar8;
          plStack_d8 = plVar16;
          plStack_d0 = plVar9;
          lStack_c8 = param_1;
          plStack_b8 = plVar12;
          if (DAT_23eede729 == '\0') {
            if (DAT_23eede728 == '\0') {
              FUN_23e97f860(lVar7,&DAT_23eedcfe0,"workers.fishing.path_utils");
              DAT_23eede728 = '\x01';
            }
            _DAT_23eede720 = FUN_23e8bdab0(_DAT_23eedd0c8);
            uVar23 = (ulonglong)uVar24 << 0x20;
            uVar21 = (ulonglong)uVar22 << 0x20;
            _DAT_23eede718 =
                 FUN_23e8d36c0(_DAT_23eede720,1,0,_DAT_23eedd0d0,_DAT_23eedd0d0,uVar21,uVar23);
            uVar23 = uVar23 & 0xffffffff00000000;
            DAT_23eede758 =
                 FUN_23e8d36c0(_DAT_23eede720,0x2d,3,DAT_23eedd038,DAT_23eedd038,
                               uVar21 & 0xffffffff00000000,uVar23);
            uVar26 = (ulonglong)uVar27 << 0x20;
            uVar21 = (ulonglong)uVar25 << 0x20;
            uVar23 = uVar23 & 0xffffffff00000000;
            DAT_23eede730 =
                 FUN_23e8d3980(_DAT_23eede720,0x44,3,DAT_23eedd0c0,DAT_23eedd0c0,_DAT_23eedd0d8,
                               uVar23,uVar21,uVar26);
            uVar26 = uVar26 & 0xffffffff00000000;
            uVar21 = uVar21 & 0xffffffff00000000;
            DAT_23eede770 =
                 FUN_23e8d3980(_DAT_23eede720,10,3,DAT_23eedd020,DAT_23eedd020,_DAT_23eedd0e0,
                               uVar23 & 0xffffffff00000000,uVar21,uVar26);
            uVar10 = DAT_23eedd0b8;
            DAT_23eede748 =
                 FUN_23e8d3980(_DAT_23eede720,0x32,3,DAT_23eedd0b8,DAT_23eedd0b8,_DAT_23eedd0e8,1,
                               uVar21 & 0xffffffff00000000,uVar26 & 0xffffffff00000000);
            uVar20 = (undefined4)((ulonglong)uVar10 >> 0x20);
            DAT_23eede729 = '\x01';
          }
          FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cdd0,DAT_23ed6a4a8);
          puVar13 = (undefined8 *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cd48);
          uVar10 = 0;
          if (puVar13 != (undefined8 *)0x0) {
            uVar10 = *puVar13;
          }
          uVar14 = PyUnicode_GetLength(uVar10);
          lVar15 = PyUnicode_Find(uVar10,DAT_23ed6cf48,0,uVar14,CONCAT44(uVar20,0xffffffff));
          if (lVar15 != -1) {
            uVar10 = PyUnicode_Substring(uVar10,0,lVar15);
            FUN_23a3881f0(DAT_23eedcfd0,DAT_23ed6cd50,uVar10);
          }
          plVar8 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cda0);
          if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
            uVar10 = PyModule_GetDict(DAT_23ed6a4a0);
            FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cda0,uVar10);
            puVar13 = DAT_23ed6a470;
            if (DAT_23ed6a470 == (undefined8 *)0x0) goto LAB_23e828769;
LAB_23e827fe0:
            DAT_23ed6a470 = (undefined8 *)*puVar13;
            *puVar13 = 1;
            DAT_23ed6a468 = DAT_23ed6a468 + -1;
          }
          else {
            puVar13 = DAT_23ed6a470;
            if (DAT_23ed6a470 != (undefined8 *)0x0) goto LAB_23e827fe0;
LAB_23e828769:
            puVar13 = (undefined8 *)FUN_23a33a530(&DAT_23ec0f940);
          }
          pcVar3 = _PyRuntime_exref;
          lVar15 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          uVar10 = puVar13[-1];
          puVar1 = *(undefined8 **)(lVar15 + 8);
          *puVar1 = puVar13 + -2;
          puVar13[-2] = lVar15;
          puVar13[-1] = (ulonglong)((uint)uVar10 & 3) | (ulonglong)puVar1;
          *(undefined8 **)(lVar15 + 8) = puVar13 + -2;
          lVar15 = DAT_23eedcfd0;
          puVar13[2] = puVar19;
          FUN_23a3880f0(lVar15,DAT_23ed6cdc8);
          if (DAT_23ed6a478 == 0) {
            DAT_23ed6a478 = PyImport_ImportModule("importlib._bootstrap");
          }
          plVar8 = (longlong *)PyObject_GetAttrString(DAT_23ed6a478,"_spec_from_module");
          lVar15 = FUN_23e914090(lVar7,plVar8,DAT_23eede778);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          pcVar2 = _Py_TrueStruct_exref;
          if (lVar15 == 0) {
LAB_23e828a07:
            PyErr_PrintEx(0);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          FUN_23e8d9ac0(lVar15,DAT_23ed6cfa8,_Py_TrueStruct_exref);
          FUN_23a3881f0(DAT_23eedcfd0,DAT_23ed6cfa0,lVar15);
          FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cd78,_DAT_23eedd068);
          FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cd80,_DAT_23eede720);
          plVar8 = (longlong *)FUN_23e9354d0(_DAT_23eede718,DAT_23eede778);
          lVar15 = *(longlong *)(lVar7 + 0x38);
          lVar17 = *(longlong *)(lVar15 + 8);
          plVar8[0xf] = lVar17;
          *(longlong **)(lVar15 + 8) = plVar8 + 9;
          if (((lVar17 != 0) &&
              ((*(char *)(lVar17 + 0x45) == '\x01' ||
               ((ulonglong)
                (*(longlong *)(lVar17 + 0x20) + 0xb8 +
                (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
                *(ulonglong *)(lVar17 + 0x38))))) && (plVar8[0xe] != 0)) {
            plVar16 = *(longlong **)(lVar17 + 0x28);
            *(longlong **)(plVar8[0xe] + 0x10) = plVar16;
            if (plVar16 != (longlong *)0x0) {
              *plVar16 = *plVar16 + 1;
            }
          }
          *plVar8 = *plVar8 + 1;
          uVar10 = DAT_23ed6cfa0;
          *(undefined4 *)(plVar8 + 8) = 0;
          uVar14 = _DAT_23eede720;
          plVar16 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,uVar10);
          if ((plVar16 == (longlong *)0x0) || (lVar15 = *plVar16, lVar15 == 0)) {
            lVar15 = FUN_23a3a6140();
          }
          cVar5 = FUN_23e8d9ac0(lVar15,_DAT_23eedd070,uVar14);
          if (cVar5 != '\0') {
            plVar16 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cfa0);
            if ((plVar16 == (longlong *)0x0) || (lVar15 = *plVar16, lVar15 == 0)) {
              lVar15 = FUN_23a3a6140();
            }
            cVar5 = FUN_23e8d9ac0(lVar15,_DAT_23eedd078,pcVar2);
            pcVar2 = _Py_NoneStruct_exref;
            if (cVar5 != '\0') {
              FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cf20,_Py_NoneStruct_exref);
              if ((DAT_23ed6a210 == 0) &&
                 (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec5e349), DAT_23ed6a210 == 0)) {
                FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS",
                              "\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
                abort();
              }
              FUN_23a3880f0(DAT_23eedcfd0,_DAT_23eedd080,DAT_23ed6a210);
              if ((DAT_23ed6a4b8 == 0) &&
                 (DAT_23ed6a4b8 = PyImport_ImportModule(&DAT_23ec5e386), DAT_23ed6a4b8 == 0)) {
                FUN_23e9364c0("%s : %s\n","IMPORT_HARD_OS",
                              "\"Unexpected failure of hard import of \'os\'\"");
                    /* WARNING: Subroutine does not return */
                abort();
              }
              FUN_23a3880f0(DAT_23eedcfd0,DAT_23eedd088,DAT_23ed6a4b8);
              uStack_110 = DAT_23eedd090;
              uStack_f0 = DAT_23ed6ccf0;
              plVar16 = DAT_23ed6a498;
              pcStack_100 = pcVar2;
              uStack_f8 = DAT_23eedd098;
              *(undefined4 *)(plVar8 + 5) = 7;
              lStack_108 = DAT_23eedcfd0;
              if (plVar16 == (longlong *)0x0) {
                plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
                if (plVar16 == (longlong *)0x0) {
                  PyErr_PrintEx(0,0);
                  Py_Exit(1);
                  goto LAB_23e828a07;
                }
                *plVar16 = *plVar16 + 1;
                DAT_23ed6a498 = plVar16;
              }
              plVar16 = (longlong *)FUN_23e95b390(lVar7,plVar16,&uStack_110);
              if (plVar16 != (longlong *)0x0) {
                if (((code *)plVar16[1] == PyModule_Type_exref) ||
                   (iVar6 = PyType_IsSubtype(), uVar10 = DAT_23eedcfe8, iVar6 != 0)) {
                  uVar14 = DAT_23eedcfe8;
                  lVar15 = DAT_23eedcfd0;
                  uVar10 = DAT_23ed6ccf0;
                  lVar17 = PyObject_GetAttr(plVar16,DAT_23eedcfe8);
                  if (lVar17 != 0) goto LAB_23e828314;
                  lVar17 = FUN_23e970390(lVar7,plVar16,lVar15,uVar14,uVar10);
                }
                else {
                  lVar17 = PyObject_GetAttr(plVar16,DAT_23eedcfe8);
                  if (lVar17 != 0) {
LAB_23e828314:
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    goto LAB_23e82831f;
                  }
                  lVar17 = FUN_23e8d2cf0(lVar7,plVar16,uVar10);
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (lVar17 != 0) {
LAB_23e82831f:
                  FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedcfe8,lVar17);
                  lVar15 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
                  plVar8 = *(longlong **)(lVar15 + 0x28);
                  plVar16 = (longlong *)plVar8[2];
                  *(undefined8 *)(*(longlong *)(lVar7 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
                  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                  if (plVar16 != (longlong *)0x0) {
                    plVar8[2] = 0;
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))();
                    }
                  }
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  plVar8[0xf] = 0;
                  uVar10 = DAT_23eedd0a0;
                  uVar14 = FUN_23e8dc0a0();
                  uVar18 = _PyDict_NewPresized(1);
                  PyDict_SetItem(uVar18,uVar10,uVar14);
                  uVar10 = FUN_23e93df40(FUN_23e825840,DAT_23eedd020,DAT_23eede770,0,0,uVar18,
                                         DAT_23eede778,DAT_23eedd018,0);
                  FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd020,uVar10);
                  uVar10 = DAT_23eedd0a0;
                  uVar14 = FUN_23e8dc0a0();
                  uVar18 = _PyDict_NewPresized(1);
                  PyDict_SetItem(uVar18,uVar10,uVar14);
                  uVar10 = FUN_23e93df40(FUN_23e826850,DAT_23eedd038,DAT_23eede758,0,0,uVar18,
                                         DAT_23eede778,DAT_23eedd030,0);
                  FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd038,uVar10);
                  uVar10 = DAT_23eedd0b0;
                  plVar8 = DAT_23eedd0a8;
                  uVar14 = _PyDict_NewPresized(2);
                  PyDict_SetItem(uVar14,uVar10,PyUnicode_Type_exref);
                  uVar10 = DAT_23eedd0a0;
                  uVar18 = FUN_23e8dc0a0();
                  PyDict_SetItem(uVar14,uVar10,uVar18);
                  uVar10 = DAT_23eedd048;
                  *plVar8 = *plVar8 + 1;
                  uVar10 = FUN_23e93df40(FUN_23e826c80,DAT_23eedd0b8,DAT_23eede748,plVar8,0,uVar14,
                                         DAT_23eede778,uVar10,0);
                  FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd0b8,uVar10);
                  uVar10 = DAT_23eedd0a0;
                  uVar14 = FUN_23e8dc0a0();
                  uVar18 = _PyDict_NewPresized(1);
                  PyDict_SetItem(uVar18,uVar10,uVar14);
                  uVar10 = FUN_23e93df40(FUN_23e827580,DAT_23eedd0c0,DAT_23eede730,0,0,uVar18,
                                         DAT_23eede778,DAT_23eedd060,0);
                  FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd0c0,uVar10);
                  plVar8 = DAT_23eede778;
                  *DAT_23eede778 = *DAT_23eede778 + 1;
                  return plVar8;
                }
              }
              uVar10 = *(undefined8 *)(lVar7 + 0x60);
              uVar14 = *(undefined8 *)(lVar7 + 0x68);
              uVar20 = 7;
              plVar16 = *(longlong **)(lVar7 + 0x70);
              goto LAB_23e8285f2;
            }
          }
          uVar10 = *(undefined8 *)(lVar7 + 0x60);
          uVar14 = *(undefined8 *)(lVar7 + 0x68);
          uVar20 = 1;
          plVar16 = *(longlong **)(lVar7 + 0x70);
LAB_23e8285f2:
          *(undefined8 *)(lVar7 + 0x70) = 0;
          *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
          plVar9 = DAT_23ed6a4f8;
          if (plVar16 == (longlong *)0x0) {
            if (DAT_23ed6a4f8 == (longlong *)0x0) {
              plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              plVar16 = (longlong *)*DAT_23ed6a4f8;
              *DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = plVar16;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            plVar9[2] = 0;
            plVar9[3] = (longlong)plVar8;
            *plVar8 = *plVar8 + 1;
            lVar15 = *(longlong *)(pcVar3 + 0x1f8);
            *(undefined4 *)(plVar9 + 4) = 0xffffffff;
            lVar15 = *(longlong *)(lVar15 + 0x10);
            *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
            lVar15 = *(longlong *)(lVar15 + 0x2e8);
            lVar17 = plVar9[-1];
            puVar19 = *(undefined8 **)(lVar15 + 8);
            *puVar19 = plVar9 + -2;
            plVar9[-2] = lVar15;
            plVar9[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
            *(longlong **)(lVar15 + 8) = plVar9 + -2;
            plVar11 = plVar9;
          }
          else {
            plVar11 = plVar16;
            if ((longlong *)plVar16[3] != plVar8) {
              if (DAT_23ed6a4f8 == (longlong *)0x0) {
                plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                plVar11 = (longlong *)*DAT_23ed6a4f8;
                *DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = plVar11;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              plVar9[3] = (longlong)plVar8;
              *plVar8 = *plVar8 + 1;
              lVar15 = *(longlong *)(pcVar3 + 0x1f8);
              *(undefined4 *)(plVar9 + 4) = 0xffffffff;
              lVar15 = *(longlong *)(lVar15 + 0x10);
              *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
              lVar15 = *(longlong *)(lVar15 + 0x2e8);
              lVar17 = plVar9[-1];
              puVar19 = *(undefined8 **)(lVar15 + 8);
              *puVar19 = plVar9 + -2;
              plVar9[-2] = lVar15;
              plVar9[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
              lVar17 = *plVar16;
              *(longlong **)(lVar15 + 8) = plVar9 + -2;
              plVar9[2] = (longlong)plVar16;
              plVar11 = plVar9;
              if (lVar17 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
            }
          }
          lVar15 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
          plVar8 = *(longlong **)(lVar15 + 0x28);
          plVar16 = (longlong *)plVar8[2];
          *(undefined8 *)(*(longlong *)(lVar7 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
          *(undefined4 *)(plVar8 + 8) = 0xffffffff;
          if (plVar16 != (longlong *)0x0) {
            plVar8[2] = 0;
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))();
            }
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar8[0xf] = 0;
          FUN_23a33aa70(lVar7,uVar10,uVar14,plVar11);
          return (longlong *)0x0;
        }
        *plVar8 = *plVar8 + 1;
        DAT_23ed6a4c0 = plVar8;
      }
      uStack_70 = uVar10;
      plStack_78 = plVar9;
      lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
      if (lVar7 == 0) {
        auStack_68 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_58 = *(longlong **)(param_1 + 0x70);
        uVar20 = 0x49;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        plVar11 = DAT_23ed6a4f8;
        plVar8 = plStack_58;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          plVar11 = DAT_23ed6a4f8;
          plVar8 = plStack_58;
        }
      }
      else {
        plVar12[4] = lVar7;
        plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        pcVar3 = PyExc_FileNotFoundError_exref;
        if (plVar8 == (longlong *)0x0) {
          auStack_68 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar8 = *(longlong **)(param_1 + 0x70);
          uVar20 = 0x49;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar11 = DAT_23ed6a4f8;
        }
        else {
          *(undefined4 *)(plVar16 + 5) = 0x49;
          uVar10 = FUN_23e914090(param_1,*(undefined8 *)pcVar3,plVar8);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          auStack_68._0_8_ = uVar10;
          uVar20 = 0x49;
          FUN_23e91b7d0(param_1,auStack_68);
          plVar11 = DAT_23ed6a4f8;
          plVar8 = plStack_58;
        }
      }
      goto joined_r0x00023e8278dc;
    }
  }
  plVar8 = *(longlong **)(param_1 + 0x70);
  auStack_68 = *(undefined1 (*) [16])(param_1 + 0x60);
  uVar20 = 0x48;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e8278dc:
  DAT_23ed6a4f8 = plVar11;
  plStack_58 = plVar8;
  if (plVar8 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar3 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar16;
    plVar11[2] = 0;
    *plVar16 = *plVar16 + 1;
    lVar7 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar15 = plVar11[-1];
    puVar19 = *(undefined8 **)(lVar7 + 8);
    *puVar19 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar19;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
    plVar8 = plVar11;
    if ((plStack_58 != (longlong *)0x0) && (*plStack_58 = *plStack_58 + -1, *plStack_58 == 0)) {
      (**(code **)(plStack_58[1] + 0x30))(plStack_58);
    }
  }
  else if ((longlong *)plVar8[3] != plVar16) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar3 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar16;
    *plVar16 = *plVar16 + 1;
    lVar7 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
    lVar15 = plVar11[-1];
    puVar19 = *(undefined8 **)(lVar7 + 8);
    *puVar19 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar19;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
    plVar11[2] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    plVar8 = plVar11;
    if ((plStack_58 != (longlong *)0x0) && (*plStack_58 = *plStack_58 + -1, *plStack_58 == 0)) {
      (**(code **)(plStack_58[1] + 0x30))();
    }
  }
  plStack_58 = plVar8;
  FUN_23e8bba40(plVar16,&DAT_23ec5e2bc,plVar9);
  if (_DAT_23eede738 == plVar16) {
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    _DAT_23eede738 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  plVar16 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar16 = plStack_58;
  auVar4 = auStack_68;
  uVar10 = auStack_68._0_8_;
  uVar14 = auStack_68._8_8_;
  plVar8[0xf] = 0;
  auStack_68 = (undefined1  [16])0x0;
  plStack_58 = (longlong *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  auStack_68 = auVar4;
  plStack_58 = plVar16;
  FUN_23a33aa70(param_1,uVar10,uVar14,plVar16);
  return (longlong *)0x0;
}
