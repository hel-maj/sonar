/* ===== 23c62a0e0 license.license_client:146 ===== */
/* ghidra_name=FUN_23c62a0e0 entry=23c62a0e0 size=4128 */

code * FUN_23c62a0e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  undefined4 uVar19;
  code *local_c0;
  code *local_b8;
  code *local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  longlong *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar8 = DAT_23ee29cb0;
  plVar2 = (longlong *)*param_3;
  if (DAT_23ee29cb0 == (longlong *)0x0) {
LAB_23c62a125:
    DAT_23ee29cb0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29ca8,DAT_23ee29d18,0x10);
  }
  else {
    lVar12 = *DAT_23ee29cb0;
    if (1 < lVar12) {
      *DAT_23ee29cb0 = lVar12 + -1;
      goto LAB_23c62a125;
    }
    if (DAT_23ee29cb0[2] != 0) {
      *DAT_23ee29cb0 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23c62a125;
    }
  }
  plVar5 = DAT_23ee29cb0;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23ee29cb0 + 9;
  lVar10 = *(longlong *)(lVar12 + 8);
  DAT_23ee29cb0[0xf] = lVar10;
  *(longlong **)(lVar12 + 8) = plVar8;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar2);
  if (plVar8 == (longlong *)0x0) {
LAB_23c62a270:
    pcVar16 = *(code **)(param_1 + 0x70);
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar14 = *(code **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar18 = _Py_NoneStruct_exref;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar19 = 0x95;
  }
  else {
    *(undefined4 *)(plVar5 + 5) = 0x95;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed6cee0);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23c62a270;
    iVar7 = FUN_23a35f020(plVar9);
    lVar12 = *plVar9 + -1;
    if (iVar7 == -1) {
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar14 = *(code **)(param_1 + 0x68);
      pcVar16 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      uVar19 = 0x95;
      pcVar18 = _Py_NoneStruct_exref;
      goto LAB_23c62a296;
    }
    *plVar9 = lVar12;
    if (lVar12 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      if (iVar7 != 0) goto LAB_23c62a983;
LAB_23c62a22c:
      pcVar18 = _Py_NoneStruct_exref;
      cVar6 = FUN_23e8d9ac0(plVar2,DAT_23ee283a8,_Py_NoneStruct_exref);
      if (cVar6 == '\0') {
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar16 = *(code **)(param_1 + 0x70);
        uVar19 = 0x98;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar14 = *(code **)(param_1 + 0x68);
      }
      else {
        cVar6 = FUN_23e8d9ac0(plVar2,DAT_23ee28390,pcVar18);
        if (cVar6 == '\0') {
          plVar8 = *(longlong **)(param_1 + 0x60);
          pcVar16 = *(code **)(param_1 + 0x70);
          uVar19 = 0x99;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar14 = *(code **)(param_1 + 0x68);
        }
        else {
          cVar6 = FUN_23e8d9ac0(plVar2,DAT_23ee283b0,_Py_FalseStruct_exref);
          if (cVar6 != '\0') {
LAB_23c62a81d:
            lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar8 = *(longlong **)(lVar12 + 0x28);
            plVar5 = (longlong *)plVar8[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
            *(undefined4 *)(plVar8 + 8) = 0xffffffff;
            if (plVar5 != (longlong *)0x0) {
              plVar8[2] = 0;
              *plVar5 = *plVar5 + -1;
              if (*plVar5 == 0) {
                (**(code **)(plVar5[1] + 0x30))();
              }
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            plVar8[0xf] = 0;
            *plVar2 = *plVar2 + -1;
            if (*plVar2 != 0) {
              return pcVar18;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return pcVar18;
          }
          plVar8 = *(longlong **)(param_1 + 0x60);
          pcVar16 = *(code **)(param_1 + 0x70);
          uVar19 = 0x9a;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar14 = *(code **)(param_1 + 0x68);
        }
      }
    }
    else {
      if (iVar7 == 0) goto LAB_23c62a22c;
LAB_23c62a983:
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar2);
      if (plVar8 == (longlong *)0x0) {
LAB_23c62afe0:
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar14 = *(code **)(param_1 + 0x68);
        pcVar16 = *(code **)(param_1 + 0x70);
        uVar19 = 0x96;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar18 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar5 + 5) = 0x96;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ee285b8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23c62afe0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        lVar10 = FUN_23ead5f40();
        lVar12 = DAT_23ee285c0;
        if (lVar10 == 0) {
          uVar19 = 0x97;
          FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
          pcVar18 = _Py_NoneStruct_exref;
          pcVar16 = local_68;
          plVar8 = local_78;
          pcVar14 = pcStack_70;
        }
        else {
          *(undefined4 *)(plVar5 + 5) = 0x97;
          plVar8 = (longlong *)
                   FUN_23e915840(param_1,lVar10,DAT_23ee28400,*(undefined8 *)(lVar12 + 0x18));
          if (plVar8 != (longlong *)0x0) {
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            goto LAB_23c62a22c;
          }
          plVar8 = *(longlong **)(param_1 + 0x60);
          pcVar16 = *(code **)(param_1 + 0x70);
          uVar19 = 0x97;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar18 = _Py_NoneStruct_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar14 = *(code **)(param_1 + 0x68);
        }
      }
    }
  }
LAB_23c62a296:
  plVar9 = *(longlong **)(param_1 + 0x138);
  local_98._8_8_ = pcVar14;
  local_98._0_8_ = plVar8;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = *plVar9 + 1;
  }
  pcVar14 = DAT_23ed6a4f8;
  local_88[0] = pcVar16;
  if (pcVar16 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar16 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    local_b8 = _PyRuntime_exref;
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x18) = plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(local_b8 + 0x1f8);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(pcVar14 + 0x24) = uVar19;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar10 = *(longlong *)(pcVar14 + -8);
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar12;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar3;
    *(code **)(lVar12 + 8) = pcVar14 + -0x10;
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    local_b8 = _PyRuntime_exref;
    *(longlong **)(pcVar14 + 0x18) = plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(local_b8 + 0x1f8);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(pcVar14 + 0x24) = uVar19;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar10 = *(longlong *)(pcVar14 + -8);
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar12;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar3;
    *(code **)(lVar12 + 8) = pcVar14 + -0x10;
    *(code **)(pcVar14 + 0x10) = pcVar16;
    *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
  }
  local_88[0] = pcVar14;
  if (((code *)local_98._0_8_ != (code *)0x0) && ((code *)local_98._0_8_ != pcVar18)) {
    FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
  }
  plVar8 = *(longlong **)(local_98._8_8_ + 0x28);
  if (local_88[0] == pcVar18) {
    pcVar16 = (code *)0x0;
  }
  else {
    pcVar16 = local_88[0];
    if (local_88[0] != (code *)0x0) {
      *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
    }
  }
  *(code **)(local_98._8_8_ + 0x28) = pcVar16;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  plVar8 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
  if (*(longlong *)local_98._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
  }
  if ((local_88[0] != (code *)0x0) &&
     (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
    (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
  }
  pcVar14 = *(code **)(param_1 + 0x138);
  local_88[0] = (code *)0x0;
  local_98 = (undefined1  [16])0x0;
  pcVar17 = *(code **)(pcVar14 + 8);
  pcVar16 = *(code **)PyExc_Exception_exref;
  if ((*(uint *)(*(longlong *)(pcVar16 + 8) + 0xa8) & 0x4000000) == 0) {
    if ((-1 < (int)*(uint *)(*(longlong *)(pcVar16 + 8) + 0xa8)) ||
       (((byte)pcVar16[0xab] & 0x40) == 0)) {
LAB_23c62a600:
      plVar8 = *(longlong **)PyExc_TypeError_exref;
      uVar11 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar13 = *(longlong **)(param_1 + 0x60);
      plVar15 = *(longlong **)(param_1 + 0x68);
      plVar4 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar8;
      *plVar8 = *plVar8 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar11;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if ((plVar4 == (longlong *)0x0) || (*plVar4 = *plVar4 + -1, *plVar4 != 0)) {
LAB_23c62a665:
        pcVar14 = *(code **)(param_1 + 0x138);
      }
      else {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
        pcVar14 = *(code **)(param_1 + 0x138);
      }
LAB_23c62a66c:
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
      lVar12 = FUN_23ead5f40();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
        local_c0 = pcStack_70;
        plVar8 = local_78;
        pcVar18 = local_68;
      }
      else {
        pcVar16 = (code *)FUN_23e8bc2f0(lVar12,DAT_23ee284c0);
        plVar8 = DAT_23ee285c8;
        if (pcVar16 == (code *)0x0) {
LAB_23c62ac70:
          local_c0 = *(code **)(param_1 + 0x68);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar8 = *(longlong **)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c62ac91;
        }
        lVar12 = *(longlong *)(param_1 + 0x10);
        plVar13 = *(longlong **)(lVar12 + 0xe20);
        if (plVar13 == (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar10 = plVar13[3];
          *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
          *(longlong *)(lVar12 + 0xe20) = lVar10;
          *plVar13 = 1;
        }
        plVar13[4] = 0;
        lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(local_b8 + 0x1f8) + 0x10) + 0x2e8);
        lVar10 = plVar13[-1];
        puVar3 = *(undefined8 **)(lVar12 + 8);
        *puVar3 = plVar13 + -2;
        plVar13[-2] = lVar12;
        plVar13[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar3;
        *(longlong **)(lVar12 + 8) = plVar13 + -2;
        plVar15 = DAT_23ed6a4c0;
        *plVar8 = *plVar8 + 1;
        plVar13[3] = (longlong)plVar8;
        uVar11 = DAT_23ed6cd28;
        if (plVar15 == (longlong *)0x0) {
          plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar15 != (longlong *)0x0) {
            *plVar15 = *plVar15 + 1;
            DAT_23ed6a4c0 = plVar15;
            goto LAB_23c62a744;
          }
          PyErr_PrintEx(0);
          pcVar17 = (code *)0x1;
          Py_Exit();
LAB_23c62a563:
          lVar12 = *(longlong *)(pcVar17 + 0x158);
          if (lVar12 != 0) {
            if (*(longlong *)(lVar12 + 0x10) < 1) goto LAB_23c62a4ba;
            lVar10 = 0;
            while (pcVar16 != *(code **)(lVar12 + 0x18 + lVar10 * 8)) {
              lVar10 = lVar10 + 1;
              if (*(longlong *)(lVar12 + 0x10) == lVar10) goto LAB_23c62a4ba;
            }
            goto LAB_23c62a66c;
          }
          do {
            if (pcVar16 == pcVar17) goto LAB_23c62a66c;
            pcVar17 = *(code **)(pcVar17 + 0x100);
          } while (pcVar17 != (code *)0x0);
          if (pcVar16 == PyBaseObject_Type_exref) goto LAB_23c62a66c;
          goto LAB_23c62a4ba;
        }
LAB_23c62a744:
        uStack_a0 = uVar11;
        local_a8 = pcVar14;
        lVar12 = FUN_23e94ed00(param_1,plVar15,&local_a8);
        if (lVar12 != 0) {
          plVar13[4] = lVar12;
          plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar8 == (longlong *)0x0) {
            local_c0 = *(code **)(param_1 + 0x68);
            plVar8 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
            if (*(longlong *)pcVar16 == 0) {
              (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
            }
            goto LAB_23c62ac91;
          }
          *(undefined4 *)(plVar5 + 5) = 0x9c;
          plVar13 = (longlong *)FUN_23e914090(param_1,pcVar16,plVar8);
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
          if (*(longlong *)pcVar16 == 0) {
            (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar13 == (longlong *)0x0) goto LAB_23c62ac70;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
          if (*(longlong *)pcVar14 == 0) {
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
          }
          plVar8 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar9;
          if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
            (**(code **)(plVar8[1] + 0x30))();
          }
          goto LAB_23c62a81d;
        }
        local_c0 = *(code **)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar18 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
        if (*(longlong *)pcVar16 == 0) {
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
      }
LAB_23c62ac91:
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
      if (*(longlong *)pcVar14 == 0) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
      }
      plVar13 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar9;
      pcVar16 = pcVar18;
      if (plVar13 == (longlong *)0x0) {
        if (pcVar18 != (code *)0x0) {
          if (plVar5 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23c62ab90;
          goto LAB_23c62acd5;
        }
      }
      else {
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
          if (pcVar18 != (code *)0x0) {
            iVar7 = 0x9c;
            goto LAB_23c62ad95;
          }
        }
        else if (pcVar18 != (code *)0x0) {
          if (*(longlong **)(pcVar18 + 0x18) != plVar5) goto LAB_23c62acd5;
          goto LAB_23c62ab90;
        }
      }
      iVar7 = 0x9c;
      goto LAB_23c62aafa;
    }
    local_c0 = *(code **)(pcVar17 + 8);
    pcVar1 = local_c0 + 0xa8;
    if ((*(uint *)pcVar1 & 0x40000000) == 0) {
      local_c0 = pcVar17;
      if (((int)*(uint *)pcVar1 < 0) && (((byte)pcVar17[0xab] & 0x40) != 0)) goto LAB_23c62a563;
    }
    else {
      pcVar17 = local_c0;
      if (*(int *)(*(longlong *)(local_c0 + 8) + 0xa8) < 0) goto LAB_23c62a563;
    }
    if (pcVar16 == local_c0) goto LAB_23c62a66c;
  }
  else {
    lVar12 = *(longlong *)(pcVar16 + 0x10);
    if (0 < lVar12) {
      lVar10 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar16 + lVar10 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar16 + lVar10 * 8 + 0x18) + 0xab) & 0x40) == 0))
        goto LAB_23c62a600;
        lVar10 = lVar10 + 1;
      } while (lVar12 != lVar10);
      lVar10 = 0;
      do {
        iVar7 = FUN_23a35ebd0(param_1,pcVar17,*(undefined8 *)(pcVar16 + lVar10 * 8 + 0x18));
        if (iVar7 != 0) goto LAB_23c62a665;
        lVar10 = lVar10 + 1;
      } while (lVar12 != lVar10);
      pcVar14 = *(code **)(param_1 + 0x138);
    }
  }
LAB_23c62a4ba:
  if ((pcVar14 == pcVar18) || (pcVar14 == (code *)0x0)) {
    plVar8 = *(longlong **)PyExc_RuntimeError_exref;
    local_c0 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar14 = *(code **)(param_1 + 0x138);
    *plVar8 = *plVar8 + 1;
    *(longlong **)(param_1 + 0x138) = plVar9;
    iVar7 = 0x94;
    if ((pcVar14 != (code *)0x0) &&
       (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
LAB_23c62b0b8:
      (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
      if (iVar7 == 0) goto LAB_23c62aaf1;
    }
  }
  else {
    plVar8 = *(longlong **)(pcVar14 + 8);
    pcVar18 = *(code **)(pcVar14 + 0x28);
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
    *plVar8 = *plVar8 + 1;
    local_c0 = pcVar14;
    if (pcVar18 != (code *)0x0) {
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      if (plVar5 == *(longlong **)(pcVar18 + 0x18)) {
        *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar18 + 0x24);
      }
      *(longlong **)(param_1 + 0x138) = plVar9;
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
      if (*(longlong *)pcVar14 == 0) {
        (*(code *)plVar8[6])(pcVar14);
        iVar7 = 0;
LAB_23c62ad95:
        pcVar16 = pcVar18;
        if (plVar5 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23c62ab90;
        if (iVar7 == 0) goto LAB_23c62ada7;
LAB_23c62acd5:
        uVar19 = 0x9c;
      }
      else {
        pcVar16 = pcVar18;
        if (plVar5 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23c62ab90;
LAB_23c62ada7:
        uVar19 = (undefined4)plVar5[5];
      }
      pcVar16 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar14 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar16 + 0x18) = plVar5;
      *plVar5 = *plVar5 + 1;
      lVar12 = *(longlong *)(local_b8 + 0x1f8);
      *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
      *(undefined4 *)(pcVar16 + 0x24) = uVar19;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar10 = *(longlong *)(pcVar16 + -8);
      puVar3 = *(undefined8 **)(lVar12 + 8);
      *puVar3 = pcVar16 + -0x10;
      *(longlong *)(pcVar16 + -0x10) = lVar12;
      *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar3;
      lVar10 = *(longlong *)pcVar18;
      *(code **)(lVar12 + 8) = pcVar16 + -0x10;
      *(code **)(pcVar16 + 0x10) = pcVar18;
      if (lVar10 == 0) {
        (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
      }
      goto LAB_23c62ab90;
    }
    *(longlong **)(param_1 + 0x138) = plVar9;
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
    if (*(longlong *)pcVar14 == 0) {
      iVar7 = 0;
      goto LAB_23c62b0b8;
    }
LAB_23c62aaf1:
    iVar7 = (int)plVar5[5];
  }
LAB_23c62aafa:
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar14 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar14;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar16 + 0x10) = 0;
  *(longlong **)(pcVar16 + 0x18) = plVar5;
  *plVar5 = *plVar5 + 1;
  lVar12 = *(longlong *)(local_b8 + 0x1f8);
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  *(int *)(pcVar16 + 0x24) = iVar7;
  lVar12 = *(longlong *)(lVar12 + 0x2e8);
  lVar10 = *(longlong *)(pcVar16 + -8);
  puVar3 = *(undefined8 **)(lVar12 + 8);
  *puVar3 = pcVar16 + -0x10;
  *(longlong *)(pcVar16 + -0x10) = lVar12;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar3;
  *(code **)(lVar12 + 8) = pcVar16 + -0x10;
LAB_23c62ab90:
  FUN_23e8bba40(plVar5,&DAT_23ec47929,plVar2,0);
  if (DAT_23ee29cb0 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    DAT_23ee29cb0 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar12 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  plVar9 = (longlong *)plVar5[2];
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar8,local_c0,pcVar16);
  return (code *)0x0;
}
