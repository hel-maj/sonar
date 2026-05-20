/* ===== 23aaa5380 __main__:117 ===== */
/* ghidra_name=FUN_23aaa5380 entry=23aaa5380 size=13439 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23aaa5380(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  longlong *plVar17;
  code *pcVar18;
  longlong **pplVar19;
  undefined4 uVar20;
  longlong lVar21;
  undefined8 extraout_XMM0_Qa;
  undefined8 uVar22;
  code **ppcStack_c8;
  code *pcStack_c0;
  longlong *plStack_b8;
  longlong *plStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar7 = _DAT_23ed90cd8;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23ed90cd8 == (longlong *)0x0) {
LAB_23aaa53c5:
    _DAT_23ed90cd8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ed90cd0,DAT_23ed90d18,0x30);
  }
  else {
    lVar10 = *_DAT_23ed90cd8;
    if (1 < lVar10) {
      *_DAT_23ed90cd8 = lVar10 + -1;
      goto LAB_23aaa53c5;
    }
    if (_DAT_23ed90cd8[2] != 0) {
      *_DAT_23ed90cd8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23aaa53c5;
    }
  }
  plVar3 = _DAT_23ed90cd8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23ed90cd8 + 9;
  lVar9 = *(longlong *)(lVar10 + 8);
  _DAT_23ed90cd8[0xf] = lVar9;
  *(longlong **)(lVar10 + 8) = plVar7;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar10 = DAT_23ed8fb50;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  if ((lVar10 == 0) &&
     (lVar10 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar10, lVar10 == 0)) {
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES",
                  "\"Unexpected failure of hard import of \'ctypes\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23ed8fc58);
  if (plVar7 == (longlong *)0x0) {
LAB_23aaa6650:
    pcVar16 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x7a;
    auStack_98._0_8_ = *(longlong *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23aaa666f:
    plVar8 = *(longlong **)(param_1 + 0x138);
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
    pcVar15 = DAT_23ed6a4f8;
    ppcStack_c8 = &DAT_23ed6a4f8;
    apcStack_88[0] = pcVar16;
    if (pcVar16 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar16 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar16;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_c0 = _PyRuntime_exref;
      *(longlong *)(pcVar15 + 0x10) = 0;
      *(longlong **)(pcVar15 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcStack_c0 + 0x1f8);
      *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(pcVar15 + 0x24) = uVar20;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar9 = *(longlong *)(pcVar15 + -8);
      plVar7 = *(longlong **)(lVar10 + 8);
      *plVar7 = (longlong)(pcVar15 + -0x10);
      *(longlong *)(pcVar15 + -0x10) = lVar10;
      *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar7;
      *(code **)(lVar10 + 8) = pcVar15 + -0x10;
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
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_c0 = _PyRuntime_exref;
      *(longlong **)(pcVar15 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcStack_c0 + 0x1f8);
      *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(pcVar15 + 0x24) = uVar20;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar9 = *(longlong *)(pcVar15 + -8);
      plVar7 = *(longlong **)(lVar10 + 8);
      *plVar7 = (longlong)(pcVar15 + -0x10);
      *(longlong *)(pcVar15 + -0x10) = lVar10;
      *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar7;
      *(code **)(lVar10 + 8) = pcVar15 + -0x10;
      *(code **)(pcVar15 + 0x10) = pcVar16;
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
      }
    }
    pcVar16 = _Py_NoneStruct_exref;
    apcStack_88[0] = pcVar15;
    if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_98._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
    }
    plVar7 = *(longlong **)(auStack_98._8_8_ + 0x28);
    if (apcStack_88[0] == pcVar16) {
      pcVar15 = (code *)0x0;
    }
    else {
      pcVar15 = apcStack_88[0];
      if (apcStack_88[0] != (code *)0x0) {
        *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
      }
    }
    *(code **)(auStack_98._8_8_ + 0x28) = pcVar15;
    if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    plVar7 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
    if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
      (**(code **)(plVar7[1] + 0x30))();
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
    apcStack_88[0] = (code *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    if (iVar6 == 0) {
      pcVar15 = *(code **)(param_1 + 0x138);
      if ((pcVar15 == pcVar16) || (pcVar15 == (code *)0x0)) {
        plStack_b8 = *(longlong **)PyExc_RuntimeError_exref;
        pcVar15 = (code *)PyUnicode_FromString("No active exception to reraise");
        *plStack_b8 = *plStack_b8 + 1;
        pcVar16 = *(code **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar8;
        if (pcVar16 == (code *)0x0) {
          plVar12 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          iVar6 = 0x78;
          plVar7 = (longlong *)0x0;
          goto LAB_23aaa7084;
        }
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
        iVar6 = 0x78;
        if (*(longlong *)pcVar16 == 0) {
          pcVar18 = (code *)0x0;
          iVar6 = 0x78;
          goto LAB_23aaa7055;
        }
LAB_23aaa6e49:
        plVar12 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
      }
      else {
        plStack_b8 = *(longlong **)(pcVar15 + 8);
        pcVar18 = *(code **)(pcVar15 + 0x28);
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
        *plStack_b8 = *plStack_b8 + 1;
        iVar6 = 0;
        pcVar16 = pcVar15;
        if (pcVar18 == (code *)0x0) {
          *(longlong **)(param_1 + 0x138) = plVar8;
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) goto LAB_23aaa7055;
        }
        else {
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          if (*(longlong **)(pcVar18 + 0x18) == plVar3) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar8;
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 != 0) goto LAB_23aaa6b50;
LAB_23aaa7055:
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
          if (pcVar18 != (code *)0x0) goto LAB_23aaa6b50;
          if (iVar6 != 0) goto LAB_23aaa6e49;
        }
        iVar6 = (int)plVar3[5];
        plVar12 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
      }
      goto LAB_23aaa7084;
    }
    plVar7 = *(longlong **)(param_1 + 0x138);
    *plVar7 = *plVar7 + 1;
    lVar10 = FUN_23ebc0cf0();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
      plStack_b8 = plStack_78;
      pcVar18 = pcStack_68;
      pcVar15 = pcStack_70;
    }
    else {
      plVar11 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fc80);
      plVar12 = _DAT_23ed8fc88;
      if (plVar11 == (longlong *)0x0) {
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar18 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar15 = *(code **)(param_1 + 0x68);
      }
      else {
        lVar10 = *(longlong *)(param_1 + 0x10);
        plVar13 = *(longlong **)(lVar10 + 0xe20);
        if (plVar13 == (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar9 = plVar13[3];
          *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
          *(longlong *)(lVar10 + 0xe20) = lVar9;
          *plVar13 = 1;
        }
        plVar13[4] = 0;
        lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) + 0x2e8);
        lVar9 = plVar13[-1];
        puVar2 = *(undefined8 **)(lVar10 + 8);
        *puVar2 = plVar13 + -2;
        plVar13[-2] = lVar10;
        plVar13[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
        *(longlong **)(lVar10 + 8) = plVar13 + -2;
        *plVar12 = *plVar12 + 1;
        plVar13[3] = (longlong)plVar12;
        uVar22 = DAT_23ed6cd28;
        pplVar19 = &DAT_23ed6a4c0;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar12 == (longlong *)0x0) goto LAB_23aaa77c5;
          *plVar12 = *plVar12 + 1;
          DAT_23ed6a4c0 = plVar12;
        }
        uStack_a0 = uVar22;
        plStack_a8 = plVar7;
        lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_a8);
        if (lVar10 == 0) {
          plStack_b8 = *(longlong **)(param_1 + 0x60);
          pcVar15 = *(code **)(param_1 + 0x68);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
        }
        else {
          plVar13[4] = lVar10;
          plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar12 == (longlong *)0x0) {
            plStack_b8 = *(longlong **)(param_1 + 0x60);
            pcVar15 = *(code **)(param_1 + 0x68);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x7d;
            plVar13 = (longlong *)FUN_23e914090(param_1,plVar11,plVar12);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar13 != (longlong *)0x0) {
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              plVar7 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar8;
              if (plVar7 != (longlong *)0x0) {
                *plVar7 = *plVar7 + -1;
                lVar10 = *plVar7;
                goto joined_r0x00023aaa69ef;
              }
              goto LAB_23aaa5531;
            }
            plStack_b8 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar15 = *(code **)(param_1 + 0x68);
          }
        }
      }
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    pcVar16 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar8;
    if (pcVar16 == (code *)0x0) {
      if (pcVar18 == (code *)0x0) {
LAB_23aaa7638:
        plVar12 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        iVar6 = 0x7d;
        goto LAB_23aaa7084;
      }
      plVar7 = (longlong *)0x0;
      if (plVar3 == *(longlong **)(pcVar18 + 0x18)) {
        plVar12 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcVar16 = pcVar18;
        goto LAB_23aaa6cf0;
      }
      plVar8 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      iVar6 = 0x7d;
    }
    else {
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
      if (*(longlong *)pcVar16 == 0) {
        iVar6 = 0x7d;
        goto LAB_23aaa7055;
      }
      if (pcVar18 == (code *)0x0) goto LAB_23aaa7638;
      iVar6 = 0x7d;
LAB_23aaa6b50:
      if (*(longlong **)(pcVar18 + 0x18) == plVar3) {
        plVar12 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        pcVar16 = pcVar18;
        goto LAB_23aaa6cf0;
      }
      if (iVar6 == 0) {
        iVar6 = (int)plVar3[5];
        plVar7 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
      }
      else {
        plVar7 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
      }
    }
  }
  else {
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23ed8fc60);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar10 = _DAT_23ed8fc70;
    if (plVar8 == (longlong *)0x0) goto LAB_23aaa6650;
    *(undefined4 *)(plVar3 + 5) = 0x7a;
    plVar7 = (longlong *)FUN_23e915840(param_1,plVar8,_DAT_23ed8fc68,*(undefined8 *)(lVar10 + 0x18))
    ;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23aaa6650;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar9 = FUN_23ebc0cf0();
    lVar10 = _DAT_23ed8fc78;
    if (lVar9 == 0) {
      uVar20 = 0x7b;
      FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
      pcVar16 = pcStack_68;
      auStack_98._0_8_ = plStack_78;
      auStack_98._8_8_ = pcStack_70;
      goto LAB_23aaa666f;
    }
    *(undefined4 *)(plVar3 + 5) = 0x7b;
    plVar7 = (longlong *)FUN_23e915840(param_1,lVar9,DAT_23ed8fbb0,*(undefined8 *)(lVar10 + 0x18));
    if (plVar7 == (longlong *)0x0) {
      auStack_98._0_8_ = *(longlong *)(param_1 + 0x60);
      pcVar16 = *(code **)(param_1 + 0x70);
      uVar20 = 0x7b;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      auStack_98._8_8_ = *(code **)(param_1 + 0x68);
      goto LAB_23aaa666f;
    }
    *plVar7 = *plVar7 + -1;
    lVar10 = *plVar7;
joined_r0x00023aaa69ef:
    if (lVar10 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
LAB_23aaa5531:
    lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
    if (*(char *)(lVar10 + 10) == '\0') {
      plVar7 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed8fc90);
      if (plVar7 == (longlong *)0x0) goto LAB_23aaa6ea9;
      lVar9 = *plVar7;
LAB_23aaa7398:
      if (lVar9 == 0) goto LAB_23aaa6ea9;
    }
    else {
      iVar6 = *(int *)(lVar10 + 0xc);
      if (*(int *)(lVar10 + 0xc) == 0) {
        *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
        iVar6 = DAT_23ec107d0;
        DAT_23ec107d0 = DAT_23ec107d0 + 1;
      }
      if (_DAT_23ec107b0 != iVar6) {
        _DAT_23ec107b0 = iVar6;
        _DAT_23ed90c98 = FUN_23e8cbd60(lVar10,_DAT_23ed8fc90,*(undefined8 *)(_DAT_23ed8fc90 + 0x18))
        ;
      }
      if (-1 < _DAT_23ed90c98) {
        lVar21 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
        lVar9 = *(longlong *)(lVar21 + 8 + _DAT_23ed90c98 * 0x10);
        if (lVar9 != 0) goto LAB_23aaa559e;
        _DAT_23ed90c98 = FUN_23e8cbd60(lVar10,_DAT_23ed8fc90,*(undefined8 *)(_DAT_23ed8fc90 + 0x18))
        ;
        if (-1 < _DAT_23ed90c98) {
          lVar9 = *(longlong *)(lVar21 + 8 + _DAT_23ed90c98 * 0x10);
          goto LAB_23aaa7398;
        }
      }
LAB_23aaa6ea9:
      plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8fc90);
      if ((plVar7 == (longlong *)0x0) || (lVar9 = *plVar7, lVar9 == 0)) {
        plVar12 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        FUN_23e915740(param_1,&plStack_78,_DAT_23ed8fc90);
        iVar6 = 0x7f;
        plStack_b8 = plStack_78;
        goto LAB_23aaa6c20;
      }
    }
LAB_23aaa559e:
    if ((DAT_23ed6a210 == 0) &&
       (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 == 0)) {
      FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS","\"Unexpected failure of hard import of \'sys\'\""
                   );
                    /* WARNING: Subroutine does not return */
      abort();
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,_DAT_23ed8fc10);
    if (plVar7 == (longlong *)0x0) {
      plStack_b8 = *(longlong **)(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      plVar12 = (longlong *)0x0;
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      iVar6 = 0x7f;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar7 = (longlong *)0x0;
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x7f;
      plVar8 = (longlong *)FUN_23e914090(param_1,lVar9,plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar8 == (longlong *)0x0) {
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        plVar12 = (longlong *)0x0;
        pcStack_68 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar7 = (longlong *)0x0;
        iVar6 = 0x7f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar8 = (longlong *)0x0;
      }
      else {
        cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23ed8fc98,plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (cVar5 == '\0') {
          plStack_b8 = *(longlong **)(param_1 + 0x60);
          pcStack_68 = *(code **)(param_1 + 0x70);
          plVar12 = (longlong *)0x0;
          pcStack_70 = *(code **)(param_1 + 0x68);
          iVar6 = 0x7f;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        else {
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fc98);
          lVar10 = _DAT_23ed8fca8;
          if (plVar7 == (longlong *)0x0) {
            plStack_b8 = *(longlong **)(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            plVar12 = (longlong *)0x0;
            pcStack_68 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar8 = (longlong *)0x0;
            iVar6 = 0x80;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar7 = (longlong *)0x0;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x80;
            plVar8 = (longlong *)
                     FUN_23e915840(param_1,plVar7,_DAT_23ed8fca0,*(undefined8 *)(lVar10 + 0x18));
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            if (plVar8 == (longlong *)0x0) {
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              plVar12 = (longlong *)0x0;
              pcStack_68 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar7 = (longlong *)0x0;
              iVar6 = 0x80;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar8 = (longlong *)0x0;
            }
            else {
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fc98);
              lVar10 = _DAT_23ed8fcb8;
              if (plVar7 == (longlong *)0x0) {
                plStack_b8 = *(longlong **)(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                plVar12 = (longlong *)0x0;
                pcStack_68 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar8 = (longlong *)0x0;
                iVar6 = 0x81;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar7 = (longlong *)0x0;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x81;
                plVar8 = (longlong *)
                         FUN_23e915840(param_1,plVar7,_DAT_23ed8fcb0,*(undefined8 *)(lVar10 + 0x18))
                ;
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                if (plVar8 == (longlong *)0x0) {
                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  plVar12 = (longlong *)0x0;
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar7 = (longlong *)0x0;
                  iVar6 = 0x81;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar8 = (longlong *)0x0;
                }
                else {
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fc98);
                  lVar10 = _DAT_23ed8fcc8;
                  if (plVar7 == (longlong *)0x0) {
                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                    pcStack_70 = *(code **)(param_1 + 0x68);
                    plVar12 = (longlong *)0x0;
                    pcStack_68 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar8 = (longlong *)0x0;
                    iVar6 = 0x82;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar7 = (longlong *)0x0;
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x82;
                    plVar8 = (longlong *)
                             FUN_23e915840(param_1,plVar7,_DAT_23ed8fcc0,
                                           *(undefined8 *)(lVar10 + 0x18));
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    if (plVar8 == (longlong *)0x0) {
                      plStack_b8 = *(longlong **)(param_1 + 0x60);
                      pcStack_70 = *(code **)(param_1 + 0x68);
                      plVar12 = (longlong *)0x0;
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar7 = (longlong *)0x0;
                      iVar6 = 0x82;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar8 = (longlong *)0x0;
                    }
                    else {
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                      if (*(char *)(lVar10 + 10) == '\0') {
                        plVar7 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed8fcd0);
                        if (plVar7 == (longlong *)0x0) goto LAB_23aaa7440;
                        lVar10 = *plVar7;
LAB_23aaa7437:
                        if (lVar10 == 0) goto LAB_23aaa7440;
                      }
                      else {
                        iVar6 = *(int *)(lVar10 + 0xc);
                        if (*(int *)(lVar10 + 0xc) == 0) {
                          *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
                          iVar6 = DAT_23ec107d0;
                          DAT_23ec107d0 = DAT_23ec107d0 + 1;
                        }
                        if (_DAT_23ec107b4 != iVar6) {
                          _DAT_23ec107b4 = iVar6;
                          _DAT_23ed90ca0 =
                               FUN_23e8cbd60(lVar10,_DAT_23ed8fcd0,
                                             *(undefined8 *)(_DAT_23ed8fcd0 + 0x18));
                        }
                        if (-1 < _DAT_23ed90ca0) {
                          lVar9 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                          if (*(longlong *)(lVar9 + 8 + _DAT_23ed90ca0 * 0x10) != 0)
                          goto LAB_23aaa57ce;
                          _DAT_23ed90ca0 =
                               FUN_23e8cbd60(lVar10,_DAT_23ed8fcd0,
                                             *(undefined8 *)(_DAT_23ed8fcd0 + 0x18));
                          if (-1 < _DAT_23ed90ca0) {
                            lVar10 = *(longlong *)(lVar9 + 8 + _DAT_23ed90ca0 * 0x10);
                            goto LAB_23aaa7437;
                          }
                        }
LAB_23aaa7440:
                        plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8fcd0);
                        if ((plVar7 == (longlong *)0x0) || (*plVar7 == 0)) {
                          plVar12 = (longlong *)0x0;
                          plVar8 = (longlong *)0x0;
                          plVar7 = (longlong *)0x0;
                          FUN_23e915740(param_1,&plStack_78,_DAT_23ed8fcd0);
                          iVar6 = 0x85;
                          plStack_b8 = plStack_78;
                          goto LAB_23aaa6c20;
                        }
                      }
LAB_23aaa57ce:
                      *(undefined4 *)(plVar3 + 5) = 0x85;
                      plVar7 = (longlong *)FUN_23e91a870(param_1);
                      if (plVar7 == (longlong *)0x0) {
                        plStack_b8 = *(longlong **)(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        plVar12 = (longlong *)0x0;
                        pcStack_68 = *(code **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar8 = (longlong *)0x0;
                        iVar6 = 0x85;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plVar7 = (longlong *)0x0;
                      }
                      else {
                        cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23ed8fcd8,plVar7);
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                        }
                        if (cVar5 == '\0') {
                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          plVar12 = (longlong *)0x0;
                          pcStack_68 = *(code **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          iVar6 = 0x85;
                          plVar8 = (longlong *)0x0;
                          plVar7 = (longlong *)0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                        }
                        else {
                          lVar10 = FUN_23ebc0cf0();
                          if (lVar10 == 0) {
                            plVar12 = (longlong *)0x0;
                            plVar8 = (longlong *)0x0;
                            FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
                            iVar6 = 0x86;
                            plStack_b8 = plStack_78;
                            plVar7 = (longlong *)0x0;
                          }
                          else {
                            plVar11 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fbb0);
                            pplVar19 = _DAT_23ed8fce0;
                            if (plVar11 == (longlong *)0x0) {
                              plStack_b8 = *(longlong **)(param_1 + 0x60);
                              pcStack_70 = *(code **)(param_1 + 0x68);
                              plVar12 = (longlong *)0x0;
                              pcStack_68 = *(code **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar8 = (longlong *)0x0;
                              iVar6 = 0x86;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              plVar7 = (longlong *)0x0;
                            }
                            else {
                              lVar10 = *(longlong *)(param_1 + 0x10);
                              plVar13 = *(longlong **)(lVar10 + 0xe20);
                              if (plVar13 == (longlong *)0x0) {
                                plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                              }
                              else {
                                lVar9 = plVar13[3];
                                *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                                *(longlong *)(lVar10 + 0xe20) = lVar9;
                                *plVar13 = 1;
                              }
                              pcStack_c0 = _PyRuntime_exref;
                              plVar13[4] = 0;
                              lVar10 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar9 = plVar13[-1];
                              puVar2 = *(undefined8 **)(lVar10 + 8);
                              *puVar2 = plVar13 + -2;
                              plVar13[-2] = lVar10;
                              plVar13[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
                              *(longlong **)(lVar10 + 8) = plVar13 + -2;
                              uVar22 = _DAT_23ed8fcd8;
                              *pplVar19 = (longlong *)((longlong)*pplVar19 + 1);
                              plVar13[3] = (longlong)pplVar19;
                              plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar22);
                              uVar22 = DAT_23ed6cd28;
                              if (plVar7 != (longlong *)0x0) {
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                  if (plVar8 == (longlong *)0x0) goto LAB_23aaa77c5;
                                  *plVar8 = *plVar8 + 1;
                                  DAT_23ed6a4c0 = plVar8;
                                }
                                pplVar19 = &plStack_a8;
                                uStack_a0 = uVar22;
                                plStack_a8 = plVar7;
                                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplVar19);
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                if (lVar10 != 0) {
                                  plVar13[4] = lVar10;
                                  ppcStack_c8 = (code **)PyUnicode_Join_exref;
                                  plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  if (plVar7 == (longlong *)0x0) {
                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *plVar11 = *plVar11 + -1;
                                    plVar8 = (longlong *)0x0;
                                    if (*plVar11 == 0) {
                                      plVar12 = (longlong *)0x0;
                                      plVar7 = (longlong *)0x0;
                                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                                      iVar6 = 0x86;
                                    }
                                    else {
                                      plVar12 = (longlong *)0x0;
                                      plVar7 = (longlong *)0x0;
                                      iVar6 = 0x86;
                                    }
                                  }
                                  else {
                                    *(undefined4 *)(plVar3 + 5) = 0x86;
                                    plVar8 = (longlong *)FUN_23e914090(param_1,plVar11,plVar7);
                                    *plVar11 = *plVar11 + -1;
                                    uVar22 = extraout_XMM0_Qa;
                                    if (*plVar11 == 0) {
                                      uVar22 = (**(code **)(plVar11[1] + 0x30))(plVar11);
                                    }
                                    *plVar7 = *plVar7 + -1;
                                    if (*plVar7 == 0) {
                                      uVar22 = (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    }
                                    if (plVar8 != (longlong *)0x0) {
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        uVar22 = (**(code **)(plVar8[1] + 0x30))(plVar8);
                                      }
                                      lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                                      if (*(char *)(lVar10 + 10) == '\0') goto LAB_23aaa77d8;
                                      iVar6 = *(int *)(lVar10 + 0xc);
                                      if (*(int *)(lVar10 + 0xc) == 0) {
                                        *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
                                        iVar6 = DAT_23ec107d0;
                                        DAT_23ec107d0 = DAT_23ec107d0 + 1;
                                      }
                                      if (_DAT_23ec107b8 != iVar6) {
                                        _DAT_23ec107b8 = iVar6;
                                        _DAT_23ed90ca8 =
                                             FUN_23e8cbd60(lVar10,_DAT_23ed8fce8,
                                                           *(undefined8 *)(_DAT_23ed8fce8 + 0x18));
                                      }
                                      if (_DAT_23ed90ca8 < 0) goto LAB_23aaa77f5;
                                      lVar9 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f))
                                      ;
                                      lVar21 = *(longlong *)(lVar9 + 8 + _DAT_23ed90ca8 * 0x10);
                                      if (lVar21 == 0) {
                                        _DAT_23ed90ca8 =
                                             FUN_23e8cbd60(lVar10,_DAT_23ed8fce8,
                                                           *(undefined8 *)(_DAT_23ed8fce8 + 0x18));
                                        if (_DAT_23ed90ca8 < 0) goto LAB_23aaa77f5;
                                        lVar21 = *(longlong *)(lVar9 + 8 + _DAT_23ed90ca8 * 0x10);
                                        goto LAB_23aaa77ec;
                                      }
LAB_23aaa5a3f:
                                      do {
                                        plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fcd8);
                                        if (plVar8 == (longlong *)0x0) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          plVar12 = (longlong *)0x0;
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar7 = (longlong *)0x0;
                                          iVar6 = 0x89;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar8 = (longlong *)0x0;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        *(undefined4 *)(plVar3 + 5) = 0x89;
                                        plVar7 = (longlong *)FUN_23e914090(param_1,lVar21,plVar8);
                                        *plVar8 = *plVar8 + -1;
                                        if (*plVar8 == 0) {
                                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                                        }
                                        if (plVar7 == (longlong *)0x0) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          plVar12 = (longlong *)0x0;
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar8 = (longlong *)0x0;
                                          iVar6 = 0x89;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        iVar6 = FUN_23a35f020(plVar7);
                                        if (iVar6 == -1) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          plVar12 = (longlong *)0x0;
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          iVar6 = 0x8a;
                                          plVar8 = (longlong *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        if (iVar6 != 0) {
                                          lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                                          if (*(char *)(lVar10 + 10) == '\0') {
                                            plVar8 = (longlong *)
                                                     FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed8fcf0);
                                            if (plVar8 == (longlong *)0x0) goto LAB_23aaa7a97;
                                            lVar9 = *plVar8;
LAB_23aaa7a8e:
                                            if (lVar9 == 0) goto LAB_23aaa7a97;
                                          }
                                          else {
                                            iVar6 = *(int *)(lVar10 + 0xc);
                                            if (*(int *)(lVar10 + 0xc) == 0) {
                                              *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
                                              iVar6 = DAT_23ec107d0;
                                              DAT_23ec107d0 = DAT_23ec107d0 + 1;
                                            }
                                            if (_DAT_23ec107bc != iVar6) {
                                              _DAT_23ec107bc = iVar6;
                                              _DAT_23ed90cb0 =
                                                   FUN_23e8cbd60(lVar10,_DAT_23ed8fcf0,
                                                                 *(undefined8 *)
                                                                  (_DAT_23ed8fcf0 + 0x18));
                                            }
                                            if (-1 < _DAT_23ed90cb0) {
                                              lVar21 = lVar10 + 0x20 +
                                                       (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                                              lVar9 = *(longlong *)
                                                       (lVar21 + 8 + _DAT_23ed90cb0 * 0x10);
                                              if (lVar9 != 0) goto LAB_23aaa5b12;
                                              _DAT_23ed90cb0 =
                                                   FUN_23e8cbd60(lVar10,_DAT_23ed8fcf0,
                                                                 *(undefined8 *)
                                                                  (_DAT_23ed8fcf0 + 0x18));
                                              if (-1 < _DAT_23ed90cb0) {
                                                lVar9 = *(longlong *)
                                                         (lVar21 + 8 + _DAT_23ed90cb0 * 0x10);
                                                goto LAB_23aaa7a8e;
                                              }
                                            }
LAB_23aaa7a97:
                                            plVar8 = (longlong *)
                                                     FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8fcf0);
                                            if ((plVar8 == (longlong *)0x0) ||
                                               (lVar9 = *plVar8, lVar9 == 0)) {
                                              plVar12 = (longlong *)0x0;
                                              plVar8 = (longlong *)0x0;
                                              FUN_23e915740(param_1,&plStack_78,_DAT_23ed8fcf0);
                                              iVar6 = 0x8b;
                                              plStack_b8 = plStack_78;
                                              goto LAB_23aaa6c20;
                                            }
                                          }
LAB_23aaa5b12:
                                          *(undefined4 *)(plVar3 + 5) = 0x8b;
                                          plVar8 = (longlong *)FUN_23e914090(param_1,lVar9,plVar7);
                                          if (plVar8 == (longlong *)0x0) {
                                            plStack_b8 = *(longlong **)(param_1 + 0x60);
                                            plVar12 = (longlong *)0x0;
                                            pcStack_68 = *(code **)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            iVar6 = 0x8b;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pcStack_70 = *(code **)(param_1 + 0x68);
                                          }
                                          else {
                                            *(undefined4 *)(plVar3 + 5) = 0x8c;
                                            plVar12 = (longlong *)
                                                      FUN_23e91bfe0(param_1,plVar8,_DAT_23ed8fcf8);
                                            if (plVar12 == (longlong *)0x0) {
                                              plStack_b8 = *(longlong **)(param_1 + 0x60);
                                              iVar6 = 0x8c;
                                              pcStack_68 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plVar12 = (longlong *)0x0;
                                              pcStack_70 = *(code **)(param_1 + 0x68);
                                            }
                                            else {
                                              iVar6 = FUN_23a35f020(plVar12);
                                              *plVar12 = *plVar12 + -1;
                                              if (*plVar12 == 0) {
                                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                                              }
                                              if (iVar6 == -1) {
                                                plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                plVar12 = (longlong *)0x0;
                                                pcStack_68 = *(code **)(param_1 + 0x70);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                iVar6 = 0x8c;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                pcStack_70 = *(code **)(param_1 + 0x68);
                                              }
                                              else if (iVar6 == 0) {
                                                plVar12 = (longlong *)
                                                          FUN_23e8bc2f0(plVar1,_DAT_23ed8fc98);
                                                if (plVar12 == (longlong *)0x0) {
                                                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  iVar6 = 0x8d;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  plVar12 = (longlong *)0x0;
                                                  pcStack_70 = *(code **)(param_1 + 0x68);
                                                }
                                                else {
                                                  *(undefined4 *)(plVar3 + 5) = 0x8d;
                                                  plVar11 = (longlong *)
                                                            FUN_23e915840(param_1,plVar12,
                                                                          _DAT_23ed8fd00,plVar8);
                                                  *plVar12 = *plVar12 + -1;
                                                  if (*plVar12 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  if (plVar11 == (longlong *)0x0) {
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    iVar6 = 0x8d;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar12 = (longlong *)0x0;
                                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                                  }
                                                  else {
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    lVar10 = FUN_23ebc0cf0();
                                                    if (lVar10 == 0) {
                                                      FUN_23e915740(param_1,&plStack_78,
                                                                    DAT_23ed8fba8);
                                                      iVar6 = 0x8e;
                                                      plStack_b8 = plStack_78;
                                                      plVar12 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      plVar13 = (longlong *)
                                                                FUN_23e8bc2f0(lVar10,DAT_23ed8fbb0);
                                                      plVar12 = _DAT_23ed8fd08;
                                                      if (plVar13 == (longlong *)0x0) {
LAB_23aaa82f6:
                                                        plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        iVar6 = 0x8e;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        pcStack_70 = *(code **)(param_1 + 0x68);
                                                      }
                                                      else {
                                                        plVar11 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),2)
                                                        ;
                                                        *plVar12 = *plVar12 + 1;
                                                        plVar11[3] = (longlong)plVar12;
                                                        lVar10 = FUN_23e94f9d0(param_1,plVar7,
                                                                               DAT_23ed6cd28);
                                                        if (lVar10 != 0) {
                                                          plVar11[4] = lVar10;
                                                          plVar12 = (longlong *)
                                                                    (*(code *)ppcStack_c8)
                                                                              (DAT_23ed6cd28,plVar11
                                                                              );
                                                          *plVar11 = *plVar11 + -1;
                                                          if (*plVar11 == 0) {
                                                            FUN_23a334bc0(plVar11);
                                                          }
                                                          if (plVar12 != (longlong *)0x0) {
                                                            *(undefined4 *)(plVar3 + 5) = 0x8e;
                                                            plVar11 = (longlong *)
                                                                      FUN_23e914090(param_1,plVar13,
                                                                                    plVar12);
                                                            *plVar13 = *plVar13 + -1;
                                                            if (*plVar13 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            *plVar12 = *plVar12 + -1;
                                                            if (*plVar12 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            if (plVar11 != (longlong *)0x0) {
                                                              *plVar11 = *plVar11 + -1;
                                                              if (*plVar11 == 0) {
                                                                FUN_23a334bc0(plVar11);
                                                              }
                                                              goto LAB_23aaa5d1a;
                                                            }
                                                            goto LAB_23aaa82f6;
                                                          }
                                                          plStack_b8 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                          pcVar16 = *(code **)(param_1 + 0x68);
                                                          pcVar15 = *(code **)(param_1 + 0x70);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          iVar6 = 0x8e;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *plVar13 = *plVar13 + -1;
                                                          lVar10 = *plVar13;
                                                          plVar12 = (longlong *)0x0;
                                                          goto joined_r0x00023aaa8182;
                                                        }
                                                        plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                        pcVar16 = *(code **)(param_1 + 0x68);
                                                        pcVar15 = *(code **)(param_1 + 0x70);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        *plVar11 = *plVar11 + -1;
                                                        lVar10 = *plVar11;
                                                        iVar6 = 0x8e;
                                                        plVar12 = (longlong *)0x0;
joined_r0x00023aaa85d1:
                                                        pcStack_68 = pcVar15;
                                                        pcStack_70 = pcVar16;
                                                        if (lVar10 == 0) {
                                                          FUN_23a334bc0(plVar11);
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                              else {
                                                lVar10 = FUN_23ebc0cf0();
                                                if (lVar10 == 0) {
                                                  FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
                                                  iVar6 = 0x90;
                                                  plStack_b8 = plStack_78;
                                                  plVar12 = (longlong *)0x0;
                                                }
                                                else {
                                                  plVar11 = (longlong *)
                                                            FUN_23e8bc2f0(lVar10,DAT_23ed8fc80);
                                                  plVar12 = _DAT_23ed8fd10;
                                                  if (plVar11 == (longlong *)0x0) {
LAB_23aaa810d:
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = (longlong *)0x0;
                                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    iVar6 = 0x90;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                                  }
                                                  else {
                                                    lVar10 = *(longlong *)(param_1 + 0x10);
                                                    plVar13 = *(longlong **)(lVar10 + 0xe20);
                                                    if (plVar13 == (longlong *)0x0) {
                                                      plVar13 = (longlong *)
                                                                FUN_23e916a20(PyTuple_Type_exref,2);
                                                    }
                                                    else {
                                                      lVar9 = plVar13[3];
                                                      *(int *)(lVar10 + 0xebc) =
                                                           *(int *)(lVar10 + 0xebc) + -1;
                                                      *(longlong *)(lVar10 + 0xe20) = lVar9;
                                                      *plVar13 = 1;
                                                    }
                                                    plVar13[4] = 0;
                                                    lVar10 = *(longlong *)
                                                              (*(longlong *)
                                                                (*(longlong *)(pcStack_c0 + 0x1f8) +
                                                                0x10) + 0x2e8);
                                                    lVar9 = plVar13[-1];
                                                    puVar2 = *(undefined8 **)(lVar10 + 8);
                                                    *puVar2 = plVar13 + -2;
                                                    plVar13[-2] = lVar10;
                                                    plVar13[-1] = (ulonglong)((uint)lVar9 & 3) |
                                                                  (ulonglong)puVar2;
                                                    *(longlong **)(lVar10 + 8) = plVar13 + -2;
                                                    plVar14 = DAT_23ed6a4c0;
                                                    *plVar12 = *plVar12 + 1;
                                                    plVar13[3] = (longlong)plVar12;
                                                    uVar22 = DAT_23ed6cd28;
                                                    if (plVar14 == (longlong *)0x0) {
                                                      plVar14 = (longlong *)
                                                                PyDict_GetItemString
                                                                          (DAT_23ed6ccc0,"format");
                                                      if (plVar14 != (longlong *)0x0) {
                                                        *plVar14 = *plVar14 + 1;
                                                        DAT_23ed6a4c0 = plVar14;
                                                        goto LAB_23aaa7c12;
                                                      }
                                                      goto LAB_23aaa77c5;
                                                    }
LAB_23aaa7c12:
                                                    uStack_a0 = uVar22;
                                                    plStack_a8 = plVar7;
                                                    lVar10 = FUN_23e94ed00(param_1,plVar14,pplVar19)
                                                    ;
                                                    if (lVar10 != 0) {
                                                      plVar13[4] = lVar10;
                                                      plVar12 = (longlong *)
                                                                (*(code *)ppcStack_c8)
                                                                          (DAT_23ed6cd28,plVar13);
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      if (plVar12 == (longlong *)0x0) {
                                                        plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                        pcVar16 = *(code **)(param_1 + 0x68);
                                                        iVar6 = 0x90;
                                                        pcVar15 = *(code **)(param_1 + 0x70);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *plVar11 = *plVar11 + -1;
                                                        lVar10 = *plVar11;
                                                        plVar12 = (longlong *)0x0;
                                                        goto joined_r0x00023aaa85d1;
                                                      }
                                                      *(undefined4 *)(plVar3 + 5) = 0x90;
                                                      plVar13 = (longlong *)
                                                                FUN_23e914090(param_1,plVar11,
                                                                              plVar12);
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      if (plVar13 != (longlong *)0x0) {
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        goto LAB_23aaa5d1a;
                                                      }
                                                      goto LAB_23aaa810d;
                                                    }
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    pcVar16 = *(code **)(param_1 + 0x68);
                                                    pcVar15 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    *plVar13 = *plVar13 + -1;
                                                    lVar10 = *plVar13;
                                                    iVar6 = 0x90;
                                                    plVar12 = (longlong *)0x0;
joined_r0x00023aaa8182:
                                                    pcStack_68 = pcVar15;
                                                    pcStack_70 = pcVar16;
                                                    if (lVar10 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                          goto LAB_23aaa6c20;
                                        }
                                        lVar9 = FUN_23ebc0cf0();
                                        lVar10 = _DAT_23ed8fd18;
                                        if (lVar9 == 0) {
                                          plVar12 = (longlong *)0x0;
                                          FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
                                          iVar6 = 0x92;
                                          plStack_b8 = plStack_78;
                                          plVar8 = (longlong *)0x0;
                                          goto LAB_23aaa6c20;
                                        }
                                        *(undefined4 *)(plVar3 + 5) = 0x92;
                                        plVar8 = (longlong *)
                                                 FUN_23e915840(param_1,lVar9,DAT_23ed8fc80,
                                                               *(undefined8 *)(lVar10 + 0x18));
                                        if (plVar8 == (longlong *)0x0) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          plVar12 = (longlong *)0x0;
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          iVar6 = 0x92;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar8 = (longlong *)0x0;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        *plVar8 = *plVar8 + -1;
                                        if (*plVar8 == 0) {
                                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                                        }
                                        plVar8 = (longlong *)0x0;
LAB_23aaa5d1a:
                                        if ((DAT_23ed77850 == 0) &&
                                           (DAT_23ed77850 = PyImport_ImportModule("ntpath"),
                                           DAT_23ed77850 == 0)) {
                                          FUN_23e9364c0("%s : %s\n","IMPORT_HARD_NTPATH",
                                                                                                                
                                                  "\"Unexpected failure of hard import of \'ntpath\'\""
                                                  );
                    /* WARNING: Subroutine does not return */
                                          abort();
                                        }
                                        plVar11 = (longlong *)
                                                  FUN_23e8bc2f0(DAT_23ed77850,_DAT_23ed8fb60);
                                        if (plVar11 == (longlong *)0x0) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          plVar12 = (longlong *)0x0;
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          iVar6 = 0x95;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fcd8);
                                        uVar22 = _DAT_23ed8fd20;
                                        if (plVar13 == (longlong *)0x0) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *plVar11 = *plVar11 + -1;
                                          if (*plVar11 == 0) {
                                            plVar12 = (longlong *)0x0;
                                            FUN_23a334bc0(plVar11);
                                            iVar6 = 0x95;
                                          }
                                          else {
                                            plVar12 = (longlong *)0x0;
                                            iVar6 = 0x95;
                                          }
                                          goto LAB_23aaa6c20;
                                        }
                                        *(undefined4 *)(plVar3 + 5) = 0x95;
                                        uStack_a0 = uVar22;
                                        plStack_a8 = plVar13;
                                        plVar12 = (longlong *)
                                                  FUN_23e94ed00(param_1,plVar11,pplVar19);
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                                        }
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                                        }
                                        if (plVar12 == (longlong *)0x0) {
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          iVar6 = 0x95;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        lVar10 = FUN_23ebc0cf0();
                                        if (lVar10 == 0) {
                                          FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
                                          iVar6 = 0x96;
                                          plStack_b8 = plStack_78;
                                          goto LAB_23aaa6c20;
                                        }
                                        plVar11 = (longlong *)FUN_23e8bc2f0(lVar10);
                                        plVar14 = _DAT_23ed8fd28;
                                        if (plVar11 == (longlong *)0x0) {
LAB_23aaa7e8f:
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          iVar6 = 0x96;
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          goto LAB_23aaa6c20;
                                        }
                                        lVar10 = *(longlong *)(param_1 + 0x10);
                                        plVar13 = *(longlong **)(lVar10 + 0xe20);
                                        if (plVar13 == (longlong *)0x0) {
                                          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                                        }
                                        else {
                                          lVar9 = plVar13[3];
                                          *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                                          *(longlong *)(lVar10 + 0xe20) = lVar9;
                                          *plVar13 = 1;
                                        }
                                        plVar13[4] = 0;
                                        lVar10 = *(longlong *)
                                                  (*(longlong *)
                                                    (*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) +
                                                  0x2e8);
                                        lVar9 = plVar13[-1];
                                        puVar2 = *(undefined8 **)(lVar10 + 8);
                                        *puVar2 = plVar13 + -2;
                                        plVar13[-2] = lVar10;
                                        plVar13[-1] = (ulonglong)((uint)lVar9 & 3) |
                                                      (ulonglong)puVar2;
                                        *(longlong **)(lVar10 + 8) = plVar13 + -2;
                                        plVar17 = DAT_23ed6a4c0;
                                        *plVar14 = *plVar14 + 1;
                                        plVar13[3] = (longlong)plVar14;
                                        uVar22 = DAT_23ed6cd28;
                                        if (plVar17 != (longlong *)0x0) {
LAB_23aaa5ea2:
                                          uStack_a0 = uVar22;
                                          plStack_a8 = plVar12;
                                          lVar10 = FUN_23e94ed00(param_1,plVar17,pplVar19);
                                          if (lVar10 == 0) {
                                            plStack_b8 = *(longlong **)(param_1 + 0x60);
                                            pcVar16 = *(code **)(param_1 + 0x68);
                                            pcVar15 = *(code **)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *plVar11 = *plVar11 + -1;
                                            if (*plVar11 == 0) {
                                              FUN_23a334bc0(plVar11);
                                            }
                                            *plVar13 = *plVar13 + -1;
                                            lVar10 = *plVar13;
                                            iVar6 = 0x96;
                                            goto joined_r0x00023aaa8182;
                                          }
                                          plVar13[4] = lVar10;
                                          plVar14 = (longlong *)
                                                    (*(code *)ppcStack_c8)(DAT_23ed6cd28,plVar13);
                                          *plVar13 = *plVar13 + -1;
                                          if (*plVar13 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          if (plVar14 == (longlong *)0x0) {
                                            plStack_b8 = *(longlong **)(param_1 + 0x60);
                                            pcVar16 = *(code **)(param_1 + 0x68);
                                            pcVar15 = *(code **)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            iVar6 = 0x96;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *plVar11 = *plVar11 + -1;
                                            lVar10 = *plVar11;
                                            goto joined_r0x00023aaa85d1;
                                          }
                                          *(undefined4 *)(plVar3 + 5) = 0x96;
                                          plVar13 = (longlong *)
                                                    FUN_23e914090(param_1,plVar11,plVar14);
                                          *plVar11 = *plVar11 + -1;
                                          if (*plVar11 == 0) {
                                            FUN_23a334bc0(plVar11);
                                          }
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                          if (plVar13 == (longlong *)0x0) goto LAB_23aaa7e8f;
                                          *plVar13 = *plVar13 + -1;
                                          if (*plVar13 == 0) {
                                            FUN_23a334bc0(plVar13);
                                          }
                                          lVar10 = FUN_23ebc0cf0();
                                          if (lVar10 == 0) {
                                            FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
                                            iVar6 = 0x97;
                                            plStack_b8 = plStack_78;
                                            goto LAB_23aaa6c20;
                                          }
                                          plVar14 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fbb0);
                                          plVar13 = _DAT_23ed8fd30;
                                          if (plVar14 == (longlong *)0x0) {
LAB_23aaa83f6:
                                            plStack_b8 = *(longlong **)(param_1 + 0x60);
                                            iVar6 = 0x97;
                                            pcStack_68 = *(code **)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pcStack_70 = *(code **)(param_1 + 0x68);
                                            goto LAB_23aaa6c20;
                                          }
                                          lVar10 = *(longlong *)(param_1 + 0x10);
                                          plVar11 = *(longlong **)(lVar10 + 0xe20);
                                          if (plVar11 == (longlong *)0x0) {
                                            plVar11 = (longlong *)
                                                      FUN_23e916a20(PyTuple_Type_exref,2);
                                          }
                                          else {
                                            lVar9 = plVar11[3];
                                            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1
                                            ;
                                            *(longlong *)(lVar10 + 0xe20) = lVar9;
                                            *plVar11 = 1;
                                          }
                                          plVar11[4] = 0;
                                          lVar10 = *(longlong *)
                                                    (*(longlong *)
                                                      (*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) +
                                                    0x2e8);
                                          lVar9 = plVar11[-1];
                                          puVar2 = *(undefined8 **)(lVar10 + 8);
                                          *puVar2 = plVar11 + -2;
                                          plVar11[-2] = lVar10;
                                          plVar11[-1] = (ulonglong)((uint)lVar9 & 3) |
                                                        (ulonglong)puVar2;
                                          *(longlong **)(lVar10 + 8) = plVar11 + -2;
                                          *plVar13 = *plVar13 + 1;
                                          plVar11[3] = (longlong)plVar13;
                                          plVar13 = (longlong *)FUN_23e9367b0(param_1,plVar12);
                                          if (plVar13 != (longlong *)0x0) {
                                            lVar10 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
                                            *plVar13 = *plVar13 + -1;
                                            if (*plVar13 == 0) {
                                              FUN_23a334bc0(plVar13);
                                            }
                                            if (lVar10 != 0) {
                                              plVar11[4] = lVar10;
                                              plVar13 = (longlong *)
                                                        (*(code *)ppcStack_c8)
                                                                  (DAT_23ed6cd28,plVar11);
                                              *plVar11 = *plVar11 + -1;
                                              if (*plVar11 == 0) {
                                                FUN_23a334bc0(plVar11);
                                              }
                                              if (plVar13 == (longlong *)0x0) {
                                                plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                iVar6 = 0x97;
                                                pcStack_68 = *(code **)(param_1 + 0x70);
                                                pcStack_70 = *(code **)(param_1 + 0x68);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                lVar10 = *plVar14;
                                                *plVar14 = lVar10 + -1;
                                                if (lVar10 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                  iVar6 = 0x97;
                                                }
                                                goto LAB_23aaa6c20;
                                              }
                                              *(undefined4 *)(plVar3 + 5) = 0x97;
                                              plVar11 = (longlong *)
                                                        FUN_23e914090(param_1,plVar14,plVar13);
                                              lVar10 = *plVar14;
                                              *plVar14 = lVar10 + -1;
                                              if (lVar10 + -1 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              *plVar13 = *plVar13 + -1;
                                              if (*plVar13 == 0) {
                                                FUN_23a334bc0(plVar13);
                                              }
                                              if (plVar11 == (longlong *)0x0) goto LAB_23aaa83f6;
                                              *plVar11 = *plVar11 + -1;
                                              if (*plVar11 == 0) {
                                                FUN_23a334bc0(plVar11);
                                              }
                                              lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                                              if (*(char *)(lVar10 + 10) == '\0') {
                                                plVar11 = (longlong *)
                                                          FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed8fd38
                                                                       );
                                                if (plVar11 == (longlong *)0x0) goto LAB_23aaa8367;
                                                lVar9 = *plVar11;
LAB_23aaa835e:
                                                if (lVar9 == 0) goto LAB_23aaa8367;
                                              }
                                              else {
                                                iVar6 = *(int *)(lVar10 + 0xc);
                                                if (*(int *)(lVar10 + 0xc) == 0) {
                                                  *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
                                                  iVar6 = DAT_23ec107d0;
                                                  DAT_23ec107d0 = DAT_23ec107d0 + 1;
                                                }
                                                if (_DAT_23ec107c0 != iVar6) {
                                                  _DAT_23ec107c0 = iVar6;
                                                  _DAT_23ed90cb8 =
                                                       FUN_23e8cbd60(lVar10,_DAT_23ed8fd38,
                                                                     *(undefined8 *)
                                                                      (_DAT_23ed8fd38 + 0x18));
                                                }
                                                if (-1 < _DAT_23ed90cb8) {
                                                  lVar21 = lVar10 + 0x20 +
                                                           (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                                                  lVar9 = *(longlong *)
                                                           (lVar21 + 8 + _DAT_23ed90cb8 * 0x10);
                                                  if (lVar9 != 0) goto LAB_23aaa61d5;
                                                  _DAT_23ed90cb8 =
                                                       FUN_23e8cbd60(lVar10,_DAT_23ed8fd38,
                                                                     *(undefined8 *)
                                                                      (_DAT_23ed8fd38 + 0x18));
                                                  if (-1 < _DAT_23ed90cb8) {
                                                    lVar9 = *(longlong *)
                                                             (lVar21 + 8 + _DAT_23ed90cb8 * 0x10);
                                                    goto LAB_23aaa835e;
                                                  }
                                                }
LAB_23aaa8367:
                                                plVar11 = (longlong *)
                                                          FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8fd38
                                                                       );
                                                if ((plVar11 == (longlong *)0x0) ||
                                                   (lVar9 = *plVar11, lVar9 == 0)) {
                                                  FUN_23e915740(param_1,&plStack_78,_DAT_23ed8fd38);
                                                  iVar6 = 0x98;
                                                  plStack_b8 = plStack_78;
                                                  goto LAB_23aaa6c20;
                                                }
                                              }
LAB_23aaa61d5:
                                              *(undefined4 *)(plVar3 + 5) = 0x98;
                                              plVar11 = (longlong *)
                                                        FUN_23e914090(param_1,lVar9,plVar12);
                                              if (plVar11 != (longlong *)0x0) {
                                                cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23ed8fd40,plVar11)
                                                ;
                                                *plVar11 = *plVar11 + -1;
                                                if (*plVar11 == 0) {
                                                  FUN_23a334bc0(plVar11);
                                                }
                                                if (cVar5 != '\0') {
                                                  lVar10 = FUN_23ebc0cf0();
                                                  if (lVar10 == 0) {
                                                    FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8)
                                                    ;
                                                    iVar6 = 0x9b;
                                                    plStack_b8 = plStack_78;
                                                    goto LAB_23aaa6c20;
                                                  }
                                                  plVar13 = (longlong *)
                                                            FUN_23e8bc2f0(lVar10,DAT_23ed8fbb0);
                                                  plVar14 = _DAT_23ed8fd48;
                                                  if (plVar13 == (longlong *)0x0) {
LAB_23aaa8641:
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    iVar6 = 0x9b;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                                    goto LAB_23aaa6c20;
                                                  }
                                                  plVar11 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),2);
                                                  *plVar14 = *plVar14 + 1;
                                                  plVar11[3] = (longlong)plVar14;
                                                  lVar10 = FUN_23e94f9d0(param_1,plVar12,
                                                                         DAT_23ed6cd28);
                                                  if (lVar10 == 0) {
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    pcVar16 = *(code **)(param_1 + 0x68);
                                                    pcVar15 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    *plVar11 = *plVar11 + -1;
                                                    lVar10 = *plVar11;
                                                    iVar6 = 0x9b;
                                                    goto joined_r0x00023aaa85d1;
                                                  }
                                                  plVar11[4] = lVar10;
                                                  plVar14 = (longlong *)
                                                            (*(code *)ppcStack_c8)
                                                                      (DAT_23ed6cd28,plVar11);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  if (plVar14 == (longlong *)0x0) {
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    pcVar16 = *(code **)(param_1 + 0x68);
                                                    pcVar15 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    iVar6 = 0x9b;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar13 = *plVar13 + -1;
                                                    lVar10 = *plVar13;
                                                    goto joined_r0x00023aaa8182;
                                                  }
                                                  *(undefined4 *)(plVar3 + 5) = 0x9b;
                                                  plVar11 = (longlong *)
                                                            FUN_23e914090(param_1,plVar13,plVar14);
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0(plVar14);
                                                  }
                                                  if (plVar11 == (longlong *)0x0)
                                                  goto LAB_23aaa8641;
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                                                  if (*(char *)(lVar10 + 10) == '\0') {
                                                    plVar11 = (longlong *)
                                                              FUN_23a37a020(DAT_23ed8fb58,
                                                                            _DAT_23ed8fd50);
                                                    if (plVar11 == (longlong *)0x0)
                                                    goto LAB_23aaa8704;
                                                    lVar9 = *plVar11;
LAB_23aaa86fb:
                                                    if (lVar9 == 0) goto LAB_23aaa8704;
                                                  }
                                                  else {
                                                    iVar6 = *(int *)(lVar10 + 0xc);
                                                    if (*(int *)(lVar10 + 0xc) == 0) {
                                                      *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
                                                      iVar6 = DAT_23ec107d0;
                                                      DAT_23ec107d0 = DAT_23ec107d0 + 1;
                                                    }
                                                    if (_DAT_23ec107c4 != iVar6) {
                                                      _DAT_23ec107c4 = iVar6;
                                                      _DAT_23ed90cc0 =
                                                           FUN_23e8cbd60(lVar10,_DAT_23ed8fd50,
                                                                         *(undefined8 *)
                                                                          (_DAT_23ed8fd50 + 0x18));
                                                    }
                                                    if (-1 < _DAT_23ed90cc0) {
                                                      lVar21 = lVar10 + 0x20 +
                                                               (1L << (*(byte *)(lVar10 + 9) & 0x3f)
                                                               );
                                                      lVar9 = *(longlong *)
                                                               (lVar21 + 8 + _DAT_23ed90cc0 * 0x10);
                                                      if (lVar9 != 0) goto LAB_23aaa63c4;
                                                      _DAT_23ed90cc0 =
                                                           FUN_23e8cbd60(lVar10,_DAT_23ed8fd50,
                                                                         *(undefined8 *)
                                                                          (_DAT_23ed8fd50 + 0x18));
                                                      if (-1 < _DAT_23ed90cc0) {
                                                        lVar9 = *(longlong *)
                                                                 (lVar21 + 8 + _DAT_23ed90cc0 * 0x10
                                                                 );
                                                        goto LAB_23aaa86fb;
                                                      }
                                                    }
LAB_23aaa8704:
                                                    plVar11 = (longlong *)
                                                              FUN_23a37a020(DAT_23ed6ccc0,
                                                                            _DAT_23ed8fd50);
                                                    if ((plVar11 == (longlong *)0x0) ||
                                                       (lVar9 = *plVar11, lVar9 == 0)) {
                                                      FUN_23e915740(param_1,&plStack_78,
                                                                    _DAT_23ed8fd50);
                                                      iVar6 = 0x9c;
                                                      plStack_b8 = plStack_78;
                                                      goto LAB_23aaa6c20;
                                                    }
                                                  }
LAB_23aaa63c4:
                                                  *(undefined4 *)(plVar3 + 5) = 0x9c;
                                                  plVar11 = (longlong *)
                                                            FUN_23e914090(param_1,lVar9,plVar12);
                                                  if (plVar11 != (longlong *)0x0) {
                                                    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23ed8fd58,
                                                                          plVar11);
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    if (cVar5 != '\0') {
                                                      lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                                                      if (*(char *)(lVar10 + 10) == '\0') {
                                                        plVar11 = (longlong *)
                                                                  FUN_23a37a020(DAT_23ed8fb58,
                                                                                _DAT_23ed8fd60);
                                                        if (plVar11 == (longlong *)0x0)
                                                        goto LAB_23aaa8872;
                                                        lVar10 = *plVar11;
LAB_23aaa8869:
                                                        if (lVar10 == 0) goto LAB_23aaa8872;
                                                      }
                                                      else {
                                                        iVar6 = *(int *)(lVar10 + 0xc);
                                                        if (*(int *)(lVar10 + 0xc) == 0) {
                                                          *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
                                                          iVar6 = DAT_23ec107d0;
                                                          DAT_23ec107d0 = DAT_23ec107d0 + 1;
                                                        }
                                                        if (_DAT_23ec107c8 != iVar6) {
                                                          _DAT_23ec107c8 = iVar6;
                                                          _DAT_23ed90cc8 =
                                                               FUN_23e8cbd60(lVar10,_DAT_23ed8fd60,
                                                                             *(undefined8 *)
                                                                              (_DAT_23ed8fd60 + 0x18
                                                                              ));
                                                        }
                                                        if (-1 < _DAT_23ed90cc8) {
                                                          lVar9 = lVar10 + 0x20 +
                                                                  (1L << (*(byte *)(lVar10 + 9) &
                                                                         0x3f));
                                                          if (*(longlong *)
                                                               (lVar9 + 8 + _DAT_23ed90cc8 * 0x10)
                                                              != 0) goto LAB_23aaa649c;
                                                          _DAT_23ed90cc8 =
                                                               FUN_23e8cbd60(lVar10,_DAT_23ed8fd60,
                                                                             *(undefined8 *)
                                                                              (_DAT_23ed8fd60 + 0x18
                                                                              ));
                                                          if (-1 < _DAT_23ed90cc8) {
                                                            lVar10 = *(longlong *)
                                                                      (lVar9 + 8 +
                                                                      _DAT_23ed90cc8 * 0x10);
                                                            goto LAB_23aaa8869;
                                                          }
                                                        }
LAB_23aaa8872:
                                                        plVar11 = (longlong *)
                                                                  FUN_23a37a020(DAT_23ed6ccc0,
                                                                                _DAT_23ed8fd60);
                                                        if ((plVar11 == (longlong *)0x0) ||
                                                           (*plVar11 == 0)) {
                                                          FUN_23e915740(param_1,&plStack_78,
                                                                        _DAT_23ed8fd60);
                                                          iVar6 = 0x9f;
                                                          plStack_b8 = plStack_78;
                                                          goto LAB_23aaa6c20;
                                                        }
                                                      }
LAB_23aaa649c:
                                                      *(undefined4 *)(plVar3 + 5) = 0x9f;
                                                      plVar11 = (longlong *)FUN_23e91a870(param_1);
                                                      if (plVar11 != (longlong *)0x0) {
                                                        cVar5 = FUN_23e8d9ac0(plVar1,DAT_23ed8fd68,
                                                                              plVar11);
                                                        *plVar11 = *plVar11 + -1;
                                                        if (*plVar11 == 0) {
                                                          FUN_23a334bc0(plVar11);
                                                        }
                                                        if (cVar5 != '\0') {
                                                          plVar11 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar1);
                                                          if (plVar11 != (longlong *)0x0) {
                                                            plVar13 = (longlong *)
                                                                      FUN_23e8bc2f0(plVar11);
                                                            *plVar11 = *plVar11 + -1;
                                                            if (*plVar11 == 0) {
                                                              FUN_23a334bc0(plVar11);
                                                            }
                                                            if (plVar13 != (longlong *)0x0) {
                                                              plVar11 = (longlong *)
                                                                        FUN_23e8bc2f0(plVar13);
                                                              *plVar13 = *plVar13 + -1;
                                                              if (*plVar13 == 0) {
                                                                FUN_23a334bc0(plVar13);
                                                              }
                                                              if (plVar11 != (longlong *)0x0) {
                                                                plVar13 = (longlong *)
                                                                          FUN_23e8bc2f0(plVar1,
                                                  _DAT_23ed8fd80);
                                                  if (plVar13 == (longlong *)0x0) {
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    pcVar16 = *(code **)(param_1 + 0x68);
                                                    pcVar15 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    iVar6 = 0xa0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar11 = *plVar11 + -1;
                                                    lVar10 = *plVar11;
                                                    goto joined_r0x00023aaa85d1;
                                                  }
                                                  *(undefined4 *)(plVar3 + 5) = 0xa0;
                                                  plVar14 = (longlong *)
                                                            FUN_23e914090(param_1,plVar11,plVar13);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0(plVar14);
                                                    }
                                                    pcVar16 = _Py_NoneStruct_exref;
                                                    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23ed8fd88,
                                                                          _Py_NoneStruct_exref);
                                                    if (cVar5 != '\0') {
                                                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38))
                                                      ;
                                                      *(longlong *)pcVar16 =
                                                           *(longlong *)pcVar16 + 1;
                                                      *plVar7 = *plVar7 + -1;
                                                      if (*plVar7 == 0) {
                                                        FUN_23a334bc0(plVar7);
                                                      }
                                                      if ((plVar8 != (longlong *)0x0) &&
                                                         (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      *plVar1 = *plVar1 + -1;
                                                      if (*plVar1 != 0) {
                                                        return pcVar16;
                                                      }
                                                      FUN_23a334bc0(plVar1);
                                                      return pcVar16;
                                                    }
                                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                    iVar6 = 0xa3;
                                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                                    goto LAB_23aaa6c20;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  iVar6 = 0xa0;
                                                  pcStack_70 = *(code **)(param_1 + 0x68);
                                                  goto LAB_23aaa6c20;
                                                  }
                                                  }
                                                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  iVar6 = 0x9f;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  pcStack_70 = *(code **)(param_1 + 0x68);
                                                  goto LAB_23aaa6c20;
                                                  }
                                                  }
                                                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  iVar6 = 0x9c;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  pcStack_70 = *(code **)(param_1 + 0x68);
                                                  goto LAB_23aaa6c20;
                                                }
                                              }
                                              plStack_b8 = *(longlong **)(param_1 + 0x60);
                                              iVar6 = 0x98;
                                              pcStack_68 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              pcStack_70 = *(code **)(param_1 + 0x68);
                                              goto LAB_23aaa6c20;
                                            }
                                          }
                                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                                          pcVar15 = *(code **)(param_1 + 0x70);
                                          pcVar16 = *(code **)(param_1 + 0x68);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          lVar10 = *plVar14;
                                          *plVar14 = lVar10 + -1;
                                          if (lVar10 + -1 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          *plVar11 = *plVar11 + -1;
                                          lVar10 = *plVar11;
                                          iVar6 = 0x97;
                                          goto joined_r0x00023aaa85d1;
                                        }
                                        plVar17 = (longlong *)
                                                  PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                        if (plVar17 != (longlong *)0x0) {
                                          *plVar17 = *plVar17 + 1;
                                          DAT_23ed6a4c0 = plVar17;
                                          goto LAB_23aaa5ea2;
                                        }
LAB_23aaa77c5:
                                        PyErr_PrintEx(0);
                                        uVar22 = Py_Exit(1);
LAB_23aaa77d8:
                                        plVar7 = (longlong *)FUN_23a37a020(uVar22,_DAT_23ed8fce8);
                                        if (plVar7 != (longlong *)0x0) {
                                          lVar21 = *plVar7;
LAB_23aaa77ec:
                                          if (lVar21 != 0) goto LAB_23aaa5a3f;
                                        }
LAB_23aaa77f5:
                                        plVar7 = (longlong *)
                                                 FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8fce8);
                                        if ((plVar7 == (longlong *)0x0) ||
                                           (lVar21 = *plVar7, lVar21 == 0)) goto LAB_23aaa781c;
                                      } while( true );
                                    }
                                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                                    plVar8 = (longlong *)0x0;
                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar7 = (longlong *)0x0;
                                    iVar6 = 0x86;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plVar12 = (longlong *)0x0;
                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                  }
                                  goto LAB_23aaa6c20;
                                }
                              }
                              plStack_b8 = *(longlong **)(param_1 + 0x60);
                              pcVar16 = *(code **)(param_1 + 0x68);
                              pcVar15 = *(code **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                (**(code **)(plVar11[1] + 0x30))(plVar11);
                              }
                              *plVar13 = *plVar13 + -1;
                              pcStack_68 = pcVar15;
                              pcStack_70 = pcVar16;
                              if (*plVar13 == 0) {
                                plVar8 = (longlong *)0x0;
                                plVar12 = (longlong *)0x0;
                                plVar7 = (longlong *)0x0;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                                iVar6 = 0x86;
                              }
                              else {
                                iVar6 = 0x86;
                                plVar12 = (longlong *)0x0;
                                plVar8 = (longlong *)0x0;
                                plVar7 = (longlong *)0x0;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_23aaa6c20:
    pcVar15 = pcStack_70;
    if (pcStack_68 == (code *)0x0) {
      pcStack_c0 = _PyRuntime_exref;
LAB_23aaa7084:
      pcVar16 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar16 + 0x18) = plVar3;
      *(longlong *)(pcVar16 + 0x10) = 0;
      *plVar3 = *plVar3 + 1;
      *(int *)(pcVar16 + 0x24) = iVar6;
      lVar10 = *(longlong *)(pcStack_c0 + 0x1f8);
      *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
      lVar9 = *(longlong *)(pcVar16 + -8);
      plVar11 = *(longlong **)(lVar10 + 8);
      *plVar11 = (longlong)(pcVar16 + -0x10);
      *(longlong *)(pcVar16 + -0x10) = lVar10;
      *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar11;
      *(code **)(lVar10 + 8) = pcVar16 + -0x10;
      goto LAB_23aaa6cf0;
    }
    pcVar16 = pcStack_68;
    if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23aaa6cf0;
    pcStack_c0 = _PyRuntime_exref;
    pcVar18 = pcStack_68;
  }
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar4 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar4;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar16 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  *(int *)(pcVar16 + 0x24) = iVar6;
  lVar10 = *(longlong *)(pcStack_c0 + 0x1f8);
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
  lVar9 = *(longlong *)(pcVar16 + -8);
  plVar11 = *(longlong **)(lVar10 + 8);
  *plVar11 = (longlong)(pcVar16 + -0x10);
  *(longlong *)(pcVar16 + -0x10) = lVar10;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar11;
  lVar9 = *(longlong *)pcVar18;
  *(code **)(lVar10 + 8) = pcVar16 + -0x10;
  *(code **)(pcVar16 + 0x10) = pcVar18;
  if (lVar9 == 0) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
LAB_23aaa6cf0:
  FUN_23e8bba40(plVar3,"oNoooo",plVar1,0,0,plVar7,plVar8,plVar12);
  if (_DAT_23ed90cd8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ed90cd8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  plVar11 = (longlong *)plVar3[2];
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_b8,pcVar15,pcVar16);
  return (code *)0x0;
LAB_23aaa781c:
  plVar12 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  plVar7 = (longlong *)0x0;
  FUN_23e915740(param_1,&plStack_78,_DAT_23ed8fce8);
  iVar6 = 0x89;
  plStack_b8 = plStack_78;
  goto LAB_23aaa6c20;
}
