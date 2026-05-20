/* ===== 23e10fd40 telegram.bot_manager:83 ===== */
/* ghidra_name=FUN_23e10fd40 entry=23e10fd40 size=6568 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e10fd40(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined8 uVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  code *pcVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  int iStack_e0;
  code *pcStack_d8;
  code *pcStack_d0;
  undefined1 auStack_b8 [16];
  code *apcStack_a8 [2];
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  undefined8 uStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  
  plVar8 = _DAT_23eeab420;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeab420 == (longlong *)0x0) {
LAB_23e10fd85:
    _DAT_23eeab420 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab418,DAT_23eeab470,0x10);
  }
  else {
    lVar7 = *_DAT_23eeab420;
    if (1 < lVar7) {
      *_DAT_23eeab420 = lVar7 + -1;
      goto LAB_23e10fd85;
    }
    if (_DAT_23eeab420[2] != 0) {
      *_DAT_23eeab420 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e10fd85;
    }
  }
  plVar3 = _DAT_23eeab420;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeab420 + 9;
  lVar9 = *(longlong *)(lVar7 + 8);
  _DAT_23eeab420[0xf] = lVar9;
  *(longlong **)(lVar7 + 8) = plVar8;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar7 = FUN_23e9014f0();
  if (lVar7 == 0) {
    uVar21 = 0x57;
    FUN_23e915740(param_1,&uStack_78,_DAT_23eea9990);
    pcVar18 = pcStack_68;
    goto LAB_23e10fe85;
  }
  *(undefined4 *)(plVar3 + 5) = 0x57;
  plVar8 = (longlong *)FUN_23e91bfe0(param_1,lVar7,_DAT_23eea9998);
  if (plVar8 == (longlong *)0x0) {
LAB_23e10fe66:
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar21 = 0x57;
    uStack_70 = *(undefined8 *)(param_1 + 0x68);
LAB_23e10fe85:
    plVar8 = *(longlong **)(param_1 + 0x138);
    auStack_98._8_8_ = uStack_70;
    auStack_98._0_8_ = uStack_78;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
    pcVar15 = DAT_23ed6a4f8;
    apcStack_88[0] = pcVar18;
    if (pcVar18 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_d0 = _PyRuntime_exref;
      *(longlong *)(pcVar15 + 0x10) = 0;
      *(longlong **)(pcVar15 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar7 = *(longlong *)(pcStack_d0 + 0x1f8);
      *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(lVar7 + 0x10);
      *(undefined4 *)(pcVar15 + 0x24) = uVar21;
      lVar7 = *(longlong *)(lVar7 + 0x2e8);
      lVar9 = *(longlong *)(pcVar15 + -8);
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = pcVar15 + -0x10;
      *(longlong *)(pcVar15 + -0x10) = lVar7;
      *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
      *(code **)(lVar7 + 8) = pcVar15 + -0x10;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar14 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_d0 = _PyRuntime_exref;
      *(longlong **)(pcVar15 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar7 = *(longlong *)(pcStack_d0 + 0x1f8);
      *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(lVar7 + 0x10);
      *(undefined4 *)(pcVar15 + 0x24) = uVar21;
      lVar7 = *(longlong *)(lVar7 + 0x2e8);
      lVar9 = *(longlong *)(pcVar15 + -8);
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = pcVar15 + -0x10;
      *(longlong *)(pcVar15 + -0x10) = lVar7;
      *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
      *(code **)(lVar7 + 8) = pcVar15 + -0x10;
      *(code **)(pcVar15 + 0x10) = pcVar18;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
      }
    }
    pcVar18 = _Py_NoneStruct_exref;
    apcStack_88[0] = pcVar15;
    if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_98._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
    }
    plVar10 = *(longlong **)(auStack_98._8_8_ + 0x28);
    if (apcStack_88[0] == pcVar18) {
      pcVar15 = (code *)0x0;
    }
    else {
      pcVar15 = apcStack_88[0];
      if (apcStack_88[0] != (code *)0x0) {
        *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
      }
    }
    *(code **)(auStack_98._8_8_ + 0x28) = pcVar15;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    plVar10 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
    if (*(longlong *)auStack_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
    }
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
    }
    pcVar15 = *(code **)(param_1 + 0x138);
    apcStack_88[0] = (code *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    pcVar17 = *(code **)(pcVar15 + 8);
    pcVar14 = *(code **)PyExc_Exception_exref;
    if ((*(uint *)(*(longlong *)(pcVar14 + 8) + 0xa8) & 0x4000000) == 0) {
      if ((-1 < (int)*(uint *)(*(longlong *)(pcVar14 + 8) + 0xa8)) ||
         (((byte)pcVar14[0xab] & 0x40) == 0)) {
        plVar10 = *(longlong **)PyExc_TypeError_exref;
        uVar11 = PyUnicode_FromString
                           ("catching classes that do not inherit from BaseException is not allowed"
                           );
        plVar13 = *(longlong **)(param_1 + 0x60);
        plVar12 = *(longlong **)(param_1 + 0x68);
        plVar4 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar10;
        *plVar10 = *plVar10 + 1;
        *(undefined8 *)(param_1 + 0x68) = uVar11;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
          (**(code **)(plVar4[1] + 0x30))(plVar4);
        }
LAB_23e1107d5:
        pcVar19 = *(code **)(param_1 + 0x138);
LAB_23e1107dc:
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea98f8);
        plVar10 = _DAT_23eea99b8;
        if (plVar13 == (longlong *)0x0) {
LAB_23e110f70:
          pcVar17 = *(code **)(param_1 + 0x60);
          pcVar15 = *(code **)(param_1 + 0x68);
          iStack_e0 = 0x5d;
          pcVar16 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        else {
          lVar7 = *(longlong *)(param_1 + 0x10);
          pcVar14 = *(code **)(lVar7 + 0xe20);
          if (pcVar14 == (code *)0x0) {
            pcVar14 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar9 = *(longlong *)(pcVar14 + 0x18);
            *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
            *(longlong *)(lVar7 + 0xe20) = lVar9;
            *(longlong *)pcVar14 = 1;
          }
          *(longlong *)(pcVar14 + 0x20) = 0;
          lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d0 + 0x1f8) + 0x10) + 0x2e8);
          lVar9 = *(longlong *)(pcVar14 + -8);
          pcVar17 = *(code **)(lVar7 + 8);
          *(code **)pcVar17 = pcVar14 + -0x10;
          *(longlong *)(pcVar14 + -0x10) = lVar7;
          *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)pcVar17;
          *(code **)(lVar7 + 8) = pcVar14 + -0x10;
          *plVar10 = *plVar10 + 1;
          *(longlong **)(pcVar14 + 0x18) = plVar10;
          uVar11 = DAT_23ed6cd28;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + 1;
              DAT_23ed6a4c0 = plVar10;
              goto LAB_23e1108a6;
            }
            PyErr_PrintEx(0);
            pcVar15 = (code *)Py_Exit(1);
LAB_23e110493:
            lVar7 = *(longlong *)(pcVar17 + 0x158);
            pcVar19 = pcVar15;
            if (lVar7 != 0) {
              if (*(longlong *)(lVar7 + 0x10) < 1) goto LAB_23e1100d4;
              lVar9 = 0;
              while (pcVar14 != *(code **)(lVar7 + 0x18 + lVar9 * 8)) {
                lVar9 = lVar9 + 1;
                if (*(longlong *)(lVar7 + 0x10) == lVar9) goto LAB_23e1100d4;
              }
              goto LAB_23e1107dc;
            }
            do {
              if (pcVar14 == pcVar17) goto LAB_23e1107dc;
              pcVar17 = *(code **)(pcVar17 + 0x100);
            } while (pcVar17 != (code *)0x0);
            if (pcVar14 == PyBaseObject_Type_exref) goto LAB_23e1107dc;
            goto LAB_23e1100d4;
          }
LAB_23e1108a6:
          auStack_b8._8_8_ = uVar11;
          auStack_b8._0_8_ = pcVar19;
          lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,auStack_b8);
          if (lVar7 == 0) {
            pcVar17 = *(code **)(param_1 + 0x60);
            pcVar15 = *(code **)(param_1 + 0x68);
            pcVar16 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
            iStack_e0 = 0x5d;
            if (*(longlong *)pcVar14 == 0) {
              (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
              iStack_e0 = 0x5d;
            }
          }
          else {
            *(longlong *)(pcVar14 + 0x20) = lVar7;
            plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar14);
            *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
            if (*(longlong *)pcVar14 == 0) {
              (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
            }
            if (plVar10 == (longlong *)0x0) {
              pcVar17 = *(code **)(param_1 + 0x60);
              pcVar15 = *(code **)(param_1 + 0x68);
              pcVar16 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              iStack_e0 = 0x5d;
              goto LAB_23e110d00;
            }
            *(undefined4 *)(plVar3 + 5) = 0x5d;
            plVar12 = (longlong *)FUN_23e914090(param_1,plVar13);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar12 == (longlong *)0x0) goto LAB_23e110f70;
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eea98c8,_Py_FalseStruct_exref);
            if (cVar5 != '\0') {
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
              if (*(longlong *)pcVar19 == 0) {
                (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
              }
              plVar10 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar8;
              if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                (**(code **)(plVar10[1] + 0x30))();
              }
              goto LAB_23e110660;
            }
            pcVar17 = *(code **)(param_1 + 0x60);
            pcVar15 = *(code **)(param_1 + 0x68);
            iStack_e0 = 0x5e;
            pcVar16 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
          }
        }
LAB_23e110d00:
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
        if (*(longlong *)pcVar19 == 0) {
          (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
        }
        pcVar14 = *(code **)(param_1 + 0x138);
        goto LAB_23e110d41;
      }
      pcStack_d8 = *(code **)(pcVar17 + 8);
      pcVar19 = pcStack_d8 + 0xa8;
      if ((*(uint *)pcVar19 & 0x40000000) == 0) {
        pcStack_d8 = pcVar17;
        if (((int)*(uint *)pcVar19 < 0) && (((byte)pcVar17[0xab] & 0x40) != 0)) goto LAB_23e110493;
      }
      else {
        pcVar17 = pcStack_d8;
        if (*(int *)(*(longlong *)(pcStack_d8 + 8) + 0xa8) < 0) goto LAB_23e110493;
      }
      pcVar19 = pcVar15;
      if (pcVar14 == pcStack_d8) goto LAB_23e1107dc;
    }
    else {
      lVar7 = *(longlong *)(pcVar14 + 0x10);
      if (0 < lVar7) {
        lVar9 = 0;
        do {
          if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar14 + lVar9 * 8 + 0x18) + 8) + 0xa8))
             || ((*(byte *)(*(longlong *)(pcVar14 + lVar9 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
            plVar10 = *(longlong **)PyExc_TypeError_exref;
            uVar11 = PyUnicode_FromString
                               (
                               "catching classes that do not inherit from BaseException is not allowed"
                               );
            plVar13 = *(longlong **)(param_1 + 0x60);
            plVar12 = *(longlong **)(param_1 + 0x68);
            plVar4 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar10;
            *plVar10 = *plVar10 + 1;
            *(undefined8 *)(param_1 + 0x68) = uVar11;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
              (**(code **)(plVar4[1] + 0x30))(plVar4);
            }
            goto LAB_23e1107d5;
          }
          lVar9 = lVar9 + 1;
        } while (lVar7 != lVar9);
        lVar9 = 0;
        do {
          iVar6 = FUN_23a35ebd0(param_1,pcVar17,*(undefined8 *)(pcVar14 + lVar9 * 8 + 0x18));
          if (iVar6 != 0) goto LAB_23e1107d5;
          lVar9 = lVar9 + 1;
        } while (lVar7 != lVar9);
        pcVar15 = *(code **)(param_1 + 0x138);
      }
    }
LAB_23e1100d4:
    if ((pcVar15 == pcVar18) || (pcVar15 == (code *)0x0)) {
      pcVar17 = *(code **)PyExc_RuntimeError_exref;
      pcVar15 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar16 = (code *)0x0;
      pcVar14 = *(code **)(param_1 + 0x138);
      iStack_e0 = 0x55;
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
LAB_23e110d41:
      *(longlong **)(param_1 + 0x138) = plVar8;
      if (pcVar14 != (code *)0x0) goto LAB_23e11011c;
      auStack_b8._8_8_ = pcVar15;
      auStack_b8._0_8_ = pcVar17;
      if (plVar8 != (longlong *)0x0) goto LAB_23e11016d;
      apcStack_a8[0] = pcVar16;
      if (pcVar16 != (code *)0x0) goto LAB_23e110d72;
LAB_23e110ec1:
      pcVar15 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        pcVar14 = apcStack_a8[0];
      }
      else {
        pcVar14 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        pcVar14 = (code *)0x0;
      }
      *(longlong *)(pcVar15 + 0x10) = 0;
      *(longlong **)(pcVar15 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar7 = *(longlong *)(pcStack_d0 + 0x1f8);
      *(int *)(pcVar15 + 0x24) = iStack_e0;
      lVar7 = *(longlong *)(lVar7 + 0x10);
      *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(lVar7 + 0x2e8);
      lVar9 = *(longlong *)(pcVar15 + -8);
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = pcVar15 + -0x10;
      *(longlong *)(pcVar15 + -0x10) = lVar7;
      *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
      *(code **)(lVar7 + 8) = pcVar15 + -0x10;
      if ((pcVar14 != (code *)0x0) &&
         (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
      }
      pcVar17 = (code *)auStack_b8._0_8_;
      apcStack_a8[0] = pcVar15;
    }
    else {
      pcVar17 = *(code **)(pcVar15 + 8);
      pcVar16 = *(code **)(pcVar15 + 0x28);
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      pcVar14 = pcVar15;
      if (pcVar16 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar8;
        iStack_e0 = 0;
      }
      else {
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
        if (plVar3 == *(longlong **)(pcVar16 + 0x18)) {
          *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar16 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar8;
        iStack_e0 = 0;
      }
LAB_23e11011c:
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
      if (*(longlong *)pcVar14 == 0) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
        plVar8 = *(longlong **)(param_1 + 0x138);
      }
      auStack_b8._8_8_ = pcVar15;
      auStack_b8._0_8_ = pcVar17;
      apcStack_a8[0] = pcVar16;
      if (plVar8 != (longlong *)0x0) {
LAB_23e11016d:
        *plVar8 = *plVar8 + 1;
        apcStack_a8[0] = pcVar16;
      }
      if (apcStack_a8[0] == (code *)0x0) {
        if (iStack_e0 == 0) {
          iStack_e0 = (int)plVar3[5];
        }
        goto LAB_23e110ec1;
      }
      if (iStack_e0 != 0) {
LAB_23e110d72:
        pcVar14 = apcStack_a8[0];
        pcVar15 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar17 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar17;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar15 + 0x18) = plVar3;
        *plVar3 = *plVar3 + 1;
        lVar7 = *(longlong *)(pcStack_d0 + 0x1f8);
        *(int *)(pcVar15 + 0x24) = iStack_e0;
        *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
        lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
        lVar9 = *(longlong *)(pcVar15 + -8);
        puVar2 = *(undefined8 **)(lVar7 + 8);
        *puVar2 = pcVar15 + -0x10;
        *(longlong *)(pcVar15 + -0x10) = lVar7;
        *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
        *(code **)(lVar7 + 8) = pcVar15 + -0x10;
        *(code **)(pcVar15 + 0x10) = pcVar14;
        *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
        if ((apcStack_a8[0] != (code *)0x0) &&
           (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
           *(longlong *)apcStack_a8[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))(apcStack_a8[0]);
        }
        pcVar17 = (code *)auStack_b8._0_8_;
        apcStack_a8[0] = pcVar15;
      }
    }
    if ((pcVar17 != pcVar18) && (pcVar17 != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
    }
    plVar10 = *(longlong **)(auStack_b8._8_8_ + 0x28);
    if (apcStack_a8[0] == pcVar18) {
      pcVar15 = (code *)0x0;
    }
    else {
      pcVar15 = apcStack_a8[0];
      if (apcStack_a8[0] != (code *)0x0) {
        *(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + 1;
      }
    }
    *(code **)(auStack_b8._8_8_ + 0x28) = pcVar15;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    plVar10 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
    if (*(longlong *)auStack_b8._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
    }
    if ((apcStack_a8[0] != (code *)0x0) &&
       (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
       *(longlong *)apcStack_a8[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
    }
    apcStack_a8[0] = (code *)0x0;
    auStack_b8 = (undefined1  [16])0x0;
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
    if (plVar10 == (longlong *)0x0) {
      pcVar15 = *(code **)(param_1 + 0x138);
      plVar13 = *(longlong **)(param_1 + 0x60);
      *(longlong **)(param_1 + 0x138) = plVar8;
      pcVar14 = *(code **)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((pcVar15 == (code *)0x0) ||
         (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 != 0)) {
LAB_23e110e90:
        iVar6 = 0x60;
joined_r0x00023e110e99:
        pcVar15 = pcVar14;
        if (pcVar18 != (code *)0x0) goto LAB_23e110e9f;
      }
      else {
LAB_23e110b99:
        iVar6 = 0x60;
LAB_23e110b9f:
        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
        pcVar15 = pcVar14;
        if (pcVar18 != (code *)0x0) {
LAB_23e1102fb:
          pcVar14 = pcVar18;
          if (plVar3 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23e1103b0;
          if (iVar6 == 0) {
LAB_23e11030d:
            iVar6 = (int)plVar3[5];
          }
          goto LAB_23e110314;
        }
        if (iVar6 == 0) goto LAB_23e110bb7;
      }
    }
    else {
      iVar6 = FUN_23a35f020(plVar10);
      lVar7 = *plVar10 + -1;
      if (iVar6 == -1) {
        plVar13 = *(longlong **)(param_1 + 0x60);
        pcVar14 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar18 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar10 = lVar7;
        if (lVar7 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
          pcVar15 = *(code **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar8;
          if (pcVar15 != (code *)0x0) goto LAB_23e11104e;
        }
        else {
          pcVar15 = *(code **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar8;
          if (pcVar15 == (code *)0x0) goto LAB_23e110e90;
LAB_23e11104e:
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) goto LAB_23e110b99;
        }
        iVar6 = 0x60;
        pcVar15 = pcVar14;
        if (pcVar18 != (code *)0x0) goto LAB_23e110e9f;
        iVar6 = 0x60;
      }
      else {
        *plVar10 = lVar7;
        if (lVar7 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        if (iVar6 != 0) {
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
          if (plVar10 == (longlong *)0x0) {
            pcVar15 = *(code **)(param_1 + 0x138);
            plVar13 = *(longlong **)(param_1 + 0x60);
            *(longlong **)(param_1 + 0x138) = plVar8;
            pcVar14 = *(code **)(param_1 + 0x68);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((pcVar15 == (code *)0x0) ||
               (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 != 0)) {
              iVar6 = 0x61;
              goto joined_r0x00023e110e99;
            }
LAB_23e1115e5:
            iVar6 = 0x61;
            goto LAB_23e110b9f;
          }
          *(undefined4 *)(plVar3 + 5) = 0x61;
          plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23ed6cf10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar13 != (longlong *)0x0) {
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            goto LAB_23e110291;
          }
          pcVar15 = *(code **)(param_1 + 0x138);
          plVar13 = *(longlong **)(param_1 + 0x60);
          *(longlong **)(param_1 + 0x138) = plVar8;
          pcVar14 = *(code **)(param_1 + 0x68);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if (pcVar15 == (code *)0x0) {
            iVar6 = 0x61;
            pcVar15 = pcVar14;
            if (pcVar18 == (code *)0x0) {
LAB_23e1117c5:
              iVar6 = 0x61;
              goto LAB_23e110bbe;
            }
          }
          else {
            *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
            if (*(longlong *)pcVar15 == 0) goto LAB_23e1115e5;
            if (pcVar18 == (code *)0x0) goto LAB_23e1117c5;
            iVar6 = 0x61;
            pcVar15 = pcVar14;
          }
LAB_23e110e9f:
          pcVar14 = pcVar18;
          if (*(longlong **)(pcVar18 + 0x18) == plVar3) goto LAB_23e1103b0;
          goto LAB_23e110314;
        }
LAB_23e110291:
        pcVar15 = *(code **)(param_1 + 0x138);
        if ((pcVar15 == pcVar18) || (pcVar15 == (code *)0x0)) {
          plVar13 = *(longlong **)PyExc_RuntimeError_exref;
          pcVar14 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar15 = *(code **)(param_1 + 0x138);
          *plVar13 = *plVar13 + 1;
          *(longlong **)(param_1 + 0x138) = plVar8;
          iVar6 = 0x55;
          if ((pcVar15 == (code *)0x0) ||
             (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 != 0))
          goto LAB_23e110bbe;
          pcVar18 = (code *)0x0;
          goto LAB_23e110b9f;
        }
        plVar13 = *(longlong **)(pcVar15 + 8);
        pcVar18 = *(code **)(pcVar15 + 0x28);
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
        *plVar13 = *plVar13 + 1;
        if (pcVar18 != (code *)0x0) {
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          if (plVar3 == *(longlong **)(pcVar18 + 0x18)) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar8;
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) {
            iVar6 = 0;
            (*(code *)plVar13[6])();
            goto LAB_23e1102fb;
          }
          pcVar14 = pcVar18;
          if (plVar3 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23e1103b0;
          goto LAB_23e11030d;
        }
        *(longlong **)(param_1 + 0x138) = plVar8;
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
        pcVar14 = pcVar15;
        if (*(longlong *)pcVar15 == 0) {
          iVar6 = 0;
          goto LAB_23e110b9f;
        }
LAB_23e110bb7:
        iVar6 = (int)plVar3[5];
      }
    }
LAB_23e110bbe:
    pcVar15 = pcVar14;
    pcVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar18 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(pcStack_d0 + 0x1f8);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(int *)(pcVar14 + 0x24) = iVar6;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar9 = *(longlong *)(pcVar14 + -8);
    puVar2 = *(undefined8 **)(lVar7 + 8);
    *puVar2 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar7;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
    *(code **)(lVar7 + 8) = pcVar14 + -0x10;
  }
  else {
    cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eea98d8,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (cVar5 == '\0') goto LAB_23e10fe66;
    lVar7 = FUN_23e9014f0();
    if (lVar7 == 0) {
      uVar21 = 0x58;
      FUN_23e915740(param_1,&uStack_78,_DAT_23eea9990);
      pcVar18 = pcStack_68;
      goto LAB_23e10fe85;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eea99a0);
    if (plVar8 == (longlong *)0x0) {
LAB_23e110b00:
      uStack_78 = *(undefined8 *)(param_1 + 0x60);
      uStack_70 = *(undefined8 *)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      uVar21 = 0x58;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e10fe85;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
    if (plVar10 == (longlong *)0x0) {
      uStack_78 = *(undefined8 *)(param_1 + 0x60);
      uStack_70 = *(undefined8 *)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar20 = 0x58;
      uVar21 = 0x58;
      *plVar8 = *plVar8 + -1;
      lVar7 = *plVar8;
joined_r0x00023e1113a4:
      if (lVar7 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
        uVar21 = uVar20;
      }
      goto LAB_23e10fe85;
    }
    *(undefined4 *)(plVar3 + 5) = 0x58;
    plVar13 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e110b00;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
    if (plVar10 == (longlong *)0x0) {
LAB_23e111260:
      uStack_78 = *(undefined8 *)(param_1 + 0x60);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar21 = 0x5b;
      uStack_70 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e10fe85;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea99a8);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar8 == (longlong *)0x0) goto LAB_23e111260;
    *(undefined4 *)(plVar3 + 5) = 0x5b;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23eea99b0);
    if (plVar10 == (longlong *)0x0) {
      uStack_78 = *(undefined8 *)(param_1 + 0x60);
      uStack_70 = *(undefined8 *)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar20 = 0x5b;
      uVar21 = 0x5b;
      *plVar8 = *plVar8 + -1;
      lVar7 = *plVar8;
      goto joined_r0x00023e1113a4;
    }
    *(undefined4 *)(plVar3 + 5) = 0x5b;
    plVar13 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e111260;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
LAB_23e110660:
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
    if (plVar8 == (longlong *)0x0) {
      pcVar18 = *(code **)(param_1 + 0x70);
      plVar13 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar15 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e111790:
      pcStack_d0 = _PyRuntime_exref;
      if (pcVar18 != (code *)0x0) {
        pcVar14 = pcVar18;
        if (*(longlong **)(pcVar18 + 0x18) == plVar3) goto LAB_23e1103b0;
        iVar6 = 0x60;
        goto LAB_23e110314;
      }
      iVar6 = 0x60;
      pcVar14 = pcVar15;
      goto LAB_23e110bbe;
    }
    iVar6 = FUN_23a35f020(plVar8);
    lVar7 = *plVar8 + -1;
    if (iVar6 == -1) {
      plVar13 = *(longlong **)(param_1 + 0x60);
      pcVar15 = *(code **)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar8 = lVar7;
      if (lVar7 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto joined_r0x00023e111790;
    }
    *plVar8 = lVar7;
    if (lVar7 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (iVar6 == 0) {
LAB_23e1106b2:
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar8 = *(longlong **)(lVar7 + 0x28);
      plVar3 = (longlong *)plVar8[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
      *(undefined4 *)(plVar8 + 8) = 0xffffffff;
      if (plVar3 != (longlong *)0x0) {
        plVar8[2] = 0;
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))();
        }
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      pcVar18 = _Py_NoneStruct_exref;
      plVar8[0xf] = 0;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return pcVar18;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return pcVar18;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
    if (plVar8 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x61;
      plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed6cf10);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        goto LAB_23e1106b2;
      }
      pcVar18 = *(code **)(param_1 + 0x70);
      plVar13 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar15 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar18 != (code *)0x0) {
        plVar8 = *(longlong **)(pcVar18 + 0x18);
        goto joined_r0x00023e111554;
      }
LAB_23e1117d0:
      pcStack_d0 = _PyRuntime_exref;
      iVar6 = 0x61;
      pcVar14 = pcVar15;
      goto LAB_23e110bbe;
    }
    pcVar18 = *(code **)(param_1 + 0x70);
    plVar13 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar15 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar18 == (code *)0x0) goto LAB_23e1117d0;
    plVar8 = *(longlong **)(pcVar18 + 0x18);
joined_r0x00023e111554:
    pcVar14 = pcVar18;
    if (plVar8 == plVar3) goto LAB_23e1103b0;
    iVar6 = 0x61;
    pcStack_d0 = _PyRuntime_exref;
LAB_23e110314:
    pcVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar14 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(pcStack_d0 + 0x1f8);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    *(int *)(pcVar14 + 0x24) = iVar6;
    lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar14 + -8);
    puVar2 = *(undefined8 **)(lVar7 + 8);
    *puVar2 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar7;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
    lVar9 = *(longlong *)pcVar18;
    *(code **)(lVar7 + 8) = pcVar14 + -0x10;
    *(code **)(pcVar14 + 0x10) = pcVar18;
    if (lVar9 == 0) {
      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
    }
  }
LAB_23e1103b0:
  FUN_23e8bba40(plVar3,&DAT_23ec5a08f,plVar1,0);
  if (_DAT_23eeab420 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeab420 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  plVar3 = (longlong *)plVar8[2];
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar13,pcVar15,pcVar14);
  return (code *)0x0;
}
