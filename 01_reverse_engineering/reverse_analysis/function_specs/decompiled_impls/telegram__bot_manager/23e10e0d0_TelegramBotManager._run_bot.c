/* ===== 23e10e0d0 telegram.bot_manager:49 ===== */
/* ghidra_name=FUN_23e10e0d0 entry=23e10e0d0 size=4441 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e10e0d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  code *pcVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong lVar17;
  code *pcVar18;
  undefined8 *puVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  undefined8 uVar22;
  undefined4 uVar23;
  longlong *plStack_c0;
  int iStack_b0;
  longlong *plStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar6 = _DAT_23eeab448;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeab448 == (longlong *)0x0) {
LAB_23e10e117:
    _DAT_23eeab448 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab440,DAT_23eeab470,0x10);
  }
  else {
    lVar8 = *_DAT_23eeab448;
    if (1 < lVar8) {
      *_DAT_23eeab448 = lVar8 + -1;
      goto LAB_23e10e117;
    }
    if (_DAT_23eeab448[2] != 0) {
      *_DAT_23eeab448 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e10e117;
    }
  }
  plVar2 = _DAT_23eeab448;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeab448 + 9;
  lVar17 = *(longlong *)(lVar8 + 8);
  _DAT_23eeab448[0xf] = lVar17;
  *(longlong **)(lVar8 + 8) = plVar6;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar20 = _DAT_23eea98c8;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,uVar20);
  if (plVar6 == (longlong *)0x0) {
    plStack_c0 = *(longlong **)(param_1 + 0x60);
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar14 = _PyRuntime_exref;
joined_r0x00023e10e874:
    _PyRuntime_exref = pcVar14;
    if (pcVar18 == (code *)0x0) {
      iStack_b0 = 0x33;
LAB_23e10eb83:
      pcVar11 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar11 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar11 + 0x10) = 0;
      *(longlong **)(pcVar11 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      *(int *)(pcVar11 + 0x24) = iStack_b0;
      lVar8 = *(longlong *)(pcVar14 + 0x1f8);
      *(undefined4 *)(pcVar11 + 0x20) = 0xffffffff;
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
      lVar17 = *(longlong *)(pcVar11 + -8);
      puVar19 = *(undefined8 **)(lVar8 + 8);
      *puVar19 = pcVar11 + -0x10;
      *(longlong *)(pcVar11 + -0x10) = lVar8;
      *(ulonglong *)(pcVar11 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
      *(code **)(lVar8 + 8) = pcVar11 + -0x10;
      goto LAB_23e10e930;
    }
    pcVar11 = pcVar18;
    if (*(longlong **)(pcVar18 + 0x18) == plVar2) goto LAB_23e10e930;
    iStack_b0 = 0x33;
  }
  else {
    iVar5 = FUN_23a35f020(plVar6);
    lVar8 = *plVar6 + -1;
    if (iVar5 == -1) {
      plStack_c0 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar6 = lVar8;
      pcVar14 = _PyRuntime_exref;
      if (lVar8 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
        pcVar14 = _PyRuntime_exref;
      }
      goto joined_r0x00023e10e874;
    }
    *plVar6 = lVar8;
    if (lVar8 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    pcVar18 = _Py_TrueStruct_exref;
    lVar8 = _DAT_23eea9900;
    uVar20 = DAT_23eea98f8;
    if (iVar5 == 0) {
      cVar4 = FUN_23e8d9ac0(plVar1,_DAT_23eea98c8,_Py_TrueStruct_exref);
      if (cVar4 == '\0') {
        pcVar18 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar21 = 0x38;
        plVar6 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar12 = *(code **)(param_1 + 0x68);
      }
      else {
        lVar8 = *(longlong *)(DAT_23eea9890 + 0x20);
        if (*(char *)(lVar8 + 10) == '\0') {
          plVar6 = (longlong *)FUN_23a37a020(DAT_23eea9890,_DAT_23eea9908);
          if (plVar6 == (longlong *)0x0) goto LAB_23e10ed70;
          lVar17 = *plVar6;
LAB_23e10ed64:
          if (lVar17 == 0) goto LAB_23e10ed70;
        }
        else {
          iVar5 = *(int *)(lVar8 + 0xc);
          if (*(int *)(lVar8 + 0xc) == 0) {
            *(int *)(lVar8 + 0xc) = DAT_23ec14cd8;
            iVar5 = DAT_23ec14cd8;
            DAT_23ec14cd8 = DAT_23ec14cd8 + 1;
          }
          if (_DAT_23ec14cd4 != iVar5) {
            _DAT_23ec14cd4 = iVar5;
            _DAT_23eeab438 =
                 FUN_23e8cbd60(lVar8,_DAT_23eea9908,*(undefined8 *)(_DAT_23eea9908 + 0x18));
          }
          if (-1 < _DAT_23eeab438) {
            lVar3 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
            lVar17 = *(longlong *)(lVar3 + 8 + _DAT_23eeab438 * 0x10);
            if (lVar17 != 0) goto LAB_23e10e75d;
            _DAT_23eeab438 =
                 FUN_23e8cbd60(lVar8,_DAT_23eea9908,*(undefined8 *)(_DAT_23eea9908 + 0x18));
            if (-1 < _DAT_23eeab438) {
              lVar17 = *(longlong *)(lVar3 + 8 + _DAT_23eeab438 * 0x10);
              goto LAB_23e10ed64;
            }
          }
LAB_23e10ed70:
          plVar6 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eea9908);
          if ((plVar6 == (longlong *)0x0) || (lVar17 = *plVar6, lVar17 == 0)) {
            uVar21 = 0x39;
            FUN_23e915740(param_1,&plStack_78,_DAT_23eea9908);
            pcVar18 = pcStack_68;
            plVar6 = plStack_78;
            pcVar12 = pcStack_70;
            goto LAB_23e10e2f8;
          }
        }
LAB_23e10e75d:
        plVar15 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eea9910);
        if (plVar15 != (longlong *)0x0) {
          plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea9918);
          if (plVar6 == (longlong *)0x0) {
            plVar6 = *(longlong **)(param_1 + 0x60);
            pcVar12 = *(code **)(param_1 + 0x68);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            uVar21 = 0x39;
            goto LAB_23e10e2f8;
          }
          *(undefined4 *)(plVar2 + 5) = 0x39;
          pcStack_70 = pcVar18;
          plStack_78 = plVar6;
          plVar9 = (longlong *)FUN_23e9186b0(param_1,plVar15,&plStack_78,_DAT_23eea9920);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if (plVar9 != (longlong *)0x0) {
            cVar4 = FUN_23e8d9ac0(plVar1,_DAT_23eea98d0,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (cVar4 != '\0') {
              plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
              if (plVar6 != (longlong *)0x0) {
                *(undefined4 *)(plVar2 + 5) = 0x3a;
                plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar6,_DAT_23eea9928);
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                }
                if (plVar15 != (longlong *)0x0) {
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  lVar8 = _DAT_23eea9930;
                  uVar20 = DAT_23eea98f8;
                  *(undefined4 *)(plVar2 + 5) = 0x3b;
                  plVar6 = (longlong *)
                           FUN_23e915840(param_1,plVar1,uVar20,*(undefined8 *)(lVar8 + 0x18));
                  if (plVar6 != (longlong *)0x0) {
                    *plVar6 = *plVar6 + -1;
                    if (*plVar6 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar6 = *(longlong **)(lVar8 + 0x28);
                    plVar2 = (longlong *)plVar6[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar8 + 0x30);
                    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                    if (plVar2 != (longlong *)0x0) {
                      plVar6[2] = 0;
                      *plVar2 = *plVar2 + -1;
                      if (*plVar2 == 0) {
                        (**(code **)(plVar2[1] + 0x30))();
                      }
                    }
                    *plVar6 = *plVar6 + -1;
                    if (*plVar6 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                    plVar6[0xf] = 0;
                    goto LAB_23e10e281;
                  }
                  plVar6 = *(longlong **)(param_1 + 0x60);
                  pcVar18 = *(code **)(param_1 + 0x70);
                  uVar21 = 0x3b;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar12 = *(code **)(param_1 + 0x68);
                  goto LAB_23e10e2f8;
                }
              }
              plVar6 = *(longlong **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x70);
              uVar21 = 0x3a;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar12 = *(code **)(param_1 + 0x68);
              goto LAB_23e10e2f8;
            }
          }
        }
        plVar6 = *(longlong **)(param_1 + 0x60);
        pcVar18 = *(code **)(param_1 + 0x70);
        uVar21 = 0x39;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar12 = *(code **)(param_1 + 0x68);
      }
LAB_23e10e2f8:
      plVar15 = *(longlong **)(param_1 + 0x138);
      auStack_98._8_8_ = pcVar12;
      auStack_98._0_8_ = plVar6;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
      }
      pcVar12 = DAT_23ed6a4f8;
      apcStack_88[0] = pcVar18;
      if (pcVar18 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar18 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar18;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar12 + 0x10) = 0;
        *(longlong **)(pcVar12 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        *(undefined4 *)(pcVar12 + 0x24) = uVar21;
        pcVar14 = _PyRuntime_exref;
        *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
        lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
        lVar17 = *(longlong *)(pcVar12 + -8);
        puVar19 = *(undefined8 **)(lVar8 + 8);
        *puVar19 = pcVar12 + -0x10;
        *(longlong *)(pcVar12 + -0x10) = lVar8;
        *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
        *(code **)(lVar8 + 8) = pcVar12 + -0x10;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar14 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar14;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar12 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        *(undefined4 *)(pcVar12 + 0x24) = uVar21;
        pcVar14 = _PyRuntime_exref;
        *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
        lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
        lVar17 = *(longlong *)(pcVar12 + -8);
        puVar19 = *(undefined8 **)(lVar8 + 8);
        *puVar19 = pcVar12 + -0x10;
        *(longlong *)(pcVar12 + -0x10) = lVar8;
        *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
        *(code **)(lVar8 + 8) = pcVar12 + -0x10;
        *(code **)(pcVar12 + 0x10) = pcVar18;
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
        }
      }
      pcVar11 = _Py_NoneStruct_exref;
      apcStack_88[0] = pcVar12;
      if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
         ((code *)auStack_98._0_8_ != (code *)0x0)) {
        FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
      }
      plVar6 = *(longlong **)(auStack_98._8_8_ + 0x28);
      if (apcStack_88[0] == pcVar11) {
        pcVar18 = (code *)0x0;
      }
      else {
        pcVar18 = apcStack_88[0];
        if (apcStack_88[0] != (code *)0x0) {
          *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
        }
      }
      *(code **)(auStack_98._8_8_ + 0x28) = pcVar18;
      if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      plVar6 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
      if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
        (**(code **)(plVar6[1] + 0x30))();
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
      iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_Exception_exref);
      pcVar18 = _Py_FalseStruct_exref;
      uVar20 = _DAT_23eea98c8;
      if (iVar5 == 0) {
        pcVar16 = *(code **)(param_1 + 0x138);
        if ((pcVar16 == pcVar11) || (pcVar16 == (code *)0x0)) {
          plStack_c0 = *(longlong **)PyExc_RuntimeError_exref;
          pcVar12 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar16 = *(code **)(param_1 + 0x138);
          *plStack_c0 = *plStack_c0 + 1;
          iStack_b0 = 0x37;
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((pcVar16 == (code *)0x0) ||
             (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 != 0))
          goto LAB_23e10eb83;
          pcVar18 = (code *)0x0;
LAB_23e10ed21:
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))();
          pcVar16 = pcVar12;
          if (pcVar18 != (code *)0x0) goto LAB_23e10ec8c;
          if (iStack_b0 == 0) goto LAB_23e10ed42;
        }
        else {
          plStack_c0 = *(longlong **)(pcVar16 + 8);
          pcVar18 = *(code **)(pcVar16 + 0x28);
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
          *plStack_c0 = *plStack_c0 + 1;
          iStack_b0 = 0;
          pcVar12 = pcVar16;
          if (pcVar18 != (code *)0x0) {
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            if (plVar2 == *(longlong **)(pcVar18 + 0x18)) {
              *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar18 + 0x24);
              *(longlong **)(param_1 + 0x138) = plVar15;
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
              if (*(longlong *)pcVar16 == 0) goto LAB_23e10ed21;
LAB_23e10ec8c:
              pcVar12 = pcVar16;
              pcVar11 = pcVar18;
              if (*(longlong **)(pcVar18 + 0x18) == plVar2) goto LAB_23e10e930;
              if (iStack_b0 != 0) goto LAB_23e10e898;
            }
            else {
              *(longlong **)(param_1 + 0x138) = plVar15;
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
              if (*(longlong *)pcVar16 == 0) {
                (*(code *)plStack_c0[6])(pcVar16);
                goto LAB_23e10ec8c;
              }
              pcVar11 = pcVar18;
              if (*(longlong **)(pcVar18 + 0x18) == plVar2) goto LAB_23e10e930;
            }
            iStack_b0 = (int)plVar2[5];
            pcVar12 = pcVar16;
            goto LAB_23e10e898;
          }
          *(longlong **)(param_1 + 0x138) = plVar15;
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
          if (*(longlong *)pcVar16 == 0) goto LAB_23e10ed21;
LAB_23e10ed42:
          iStack_b0 = (int)plVar2[5];
        }
      }
      else {
        plVar6 = *(longlong **)(param_1 + 0x138);
        *plVar6 = *plVar6 + 1;
        cVar4 = FUN_23e8d9ac0(plVar1,uVar20,pcVar18);
        if (cVar4 == '\0') {
          plStack_c0 = *(longlong **)(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x70);
          iStack_b0 = 0x3e;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar12 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea98f8);
          plVar9 = _DAT_23eea9938;
          if (plVar7 == (longlong *)0x0) {
            plStack_c0 = *(longlong **)(param_1 + 0x60);
            pcVar12 = *(code **)(param_1 + 0x68);
            iStack_b0 = 0x3f;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
          }
          else {
            lVar8 = *(longlong *)(param_1 + 0x10);
            plVar10 = *(longlong **)(lVar8 + 0xe20);
            if (plVar10 == (longlong *)0x0) {
              plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar17 = plVar10[3];
              *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
              *(longlong *)(lVar8 + 0xe20) = lVar17;
              *plVar10 = 1;
            }
            lVar8 = *(longlong *)(pcVar14 + 0x1f8);
            plVar10[4] = 0;
            lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
            lVar17 = plVar10[-1];
            puVar19 = *(undefined8 **)(lVar8 + 8);
            *puVar19 = plVar10 + -2;
            plVar10[-2] = lVar8;
            plVar10[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
            *(longlong **)(lVar8 + 8) = plVar10 + -2;
            plVar13 = DAT_23ed6a4c0;
            *plVar9 = *plVar9 + 1;
            plVar10[3] = (longlong)plVar9;
            uVar20 = DAT_23ed6cd28;
            if (plVar13 == (longlong *)0x0) {
              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar13 == (longlong *)0x0) {
                PyErr_PrintEx(0);
                lVar8 = 1;
                Py_Exit();
                plVar6 = _DAT_23eeab430;
                plVar1 = (longlong *)*puVar19;
                if (_DAT_23eeab430 == (longlong *)0x0) {
LAB_23e10f31a:
                  _DAT_23eeab430 = (longlong *)FUN_23e91f3b0(lVar8,_DAT_23eeab428,DAT_23eeab470,8);
                }
                else {
                  lVar17 = *_DAT_23eeab430;
                  if (1 < lVar17) {
                    *_DAT_23eeab430 = lVar17 + -1;
                    goto LAB_23e10f31a;
                  }
                  if (_DAT_23eeab430[2] != 0) {
                    *_DAT_23eeab430 = lVar17 + -1;
                    if (lVar17 + -1 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    goto LAB_23e10f31a;
                  }
                }
                plVar2 = _DAT_23eeab430;
                lVar17 = *(longlong *)(lVar8 + 0x38);
                plVar6 = _DAT_23eeab430 + 9;
                lVar3 = *(longlong *)(lVar17 + 8);
                _DAT_23eeab430[0xf] = lVar3;
                *(longlong **)(lVar17 + 8) = plVar6;
                if ((lVar3 != 0) &&
                   (((*(char *)(lVar3 + 0x45) == '\x01' ||
                     ((ulonglong)
                      (*(longlong *)(lVar3 + 0x20) + 0xb8 +
                      (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <=
                      *(ulonglong *)(lVar3 + 0x38))) && (plVar2[0xe] != 0)))) {
                  plVar6 = *(longlong **)(lVar3 + 0x28);
                  *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
                  if (plVar6 != (longlong *)0x0) {
                    *plVar6 = *plVar6 + 1;
                  }
                }
                *plVar2 = *plVar2 + 1;
                uVar20 = _DAT_23eea98c8;
                *(undefined4 *)(plVar2 + 8) = 0;
                plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,uVar20);
                if (plVar6 != (longlong *)0x0) {
                  iVar5 = FUN_23a35f020(plVar6);
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  pcVar18 = _Py_NoneStruct_exref;
                  if (iVar5 != -1) {
                    if (iVar5 == 0) {
                      lVar8 = *(longlong *)(lVar8 + 0x38);
                      lVar17 = *(longlong *)(lVar8 + 8);
                      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                      plVar6 = *(longlong **)(lVar17 + 0x28);
                      plVar2 = (longlong *)plVar6[2];
                      *(undefined8 *)(lVar8 + 8) = *(undefined8 *)(lVar17 + 0x30);
                      *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                      if (plVar2 != (longlong *)0x0) {
                        plVar6[2] = 0;
                        *plVar2 = *plVar2 + -1;
                        if (*plVar2 == 0) {
                          (**(code **)(plVar2[1] + 0x30))();
                        }
                      }
                      *plVar6 = *plVar6 + -1;
                      if (*plVar6 == 0) {
                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                      }
                      plVar6[0xf] = 0;
                      goto LAB_23e10f5a6;
                    }
                    cVar4 = FUN_23e8d9ac0(plVar1,_DAT_23eea98c8,_Py_FalseStruct_exref);
                    if (cVar4 == '\0') {
                      uVar20 = *(undefined8 *)(lVar8 + 0x60);
                      uVar22 = *(undefined8 *)(lVar8 + 0x68);
                      uVar21 = 0x47;
                      pcVar18 = *(code **)(lVar8 + 0x70);
                      *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(lVar8 + 0x70) = 0;
                      goto LAB_23e10f622;
                    }
                    plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
                    if (plVar6 == (longlong *)0x0) goto LAB_23e10f908;
                    iVar5 = FUN_23a35f020(plVar6);
                    lVar17 = *plVar6 + -1;
                    if (iVar5 == -1) {
                      uVar20 = *(undefined8 *)(lVar8 + 0x60);
                      uVar22 = *(undefined8 *)(lVar8 + 0x68);
                      uVar23 = 0x4a;
                      uVar21 = 0x4a;
                      pcVar18 = *(code **)(lVar8 + 0x70);
                      *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(lVar8 + 0x70) = 0;
                      *plVar6 = lVar17;
joined_r0x00023e10fbb9:
                      if (lVar17 == 0) {
                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                        uVar21 = uVar23;
                      }
                    }
                    else {
                      *plVar6 = lVar17;
                      if (lVar17 == 0) {
                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                      }
                      if (iVar5 == 0) {
LAB_23e10f450:
                        plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
                        if (plVar6 != (longlong *)0x0) {
                          iVar5 = FUN_23a35f020(plVar6);
                          lVar17 = *plVar6 + -1;
                          if (iVar5 == -1) {
                            uVar20 = *(undefined8 *)(lVar8 + 0x60);
                            uVar22 = *(undefined8 *)(lVar8 + 0x68);
                            uVar23 = 0x4e;
                            uVar21 = 0x4e;
                            pcVar18 = *(code **)(lVar8 + 0x70);
                            *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(lVar8 + 0x70) = 0;
                            *plVar6 = lVar17;
                            goto joined_r0x00023e10fbb9;
                          }
                          *plVar6 = lVar17;
                          if (lVar17 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          if (iVar5 == 0) goto LAB_23e10f4a2;
                          plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
                          if (plVar6 != (longlong *)0x0) {
                            *(undefined4 *)(plVar2 + 5) = 0x4e;
                            plVar15 = (longlong *)FUN_23e91bfe0(lVar8,plVar6,_DAT_23eea9960);
                            *plVar6 = *plVar6 + -1;
                            if (*plVar6 == 0) {
                              (**(code **)(plVar6[1] + 0x30))(plVar6);
                            }
                            if (plVar15 != (longlong *)0x0) {
                              iVar5 = FUN_23a35f020(plVar15);
                              lVar17 = *plVar15 + -1;
                              if (iVar5 == -1) {
                                uVar20 = *(undefined8 *)(lVar8 + 0x60);
                                uVar22 = *(undefined8 *)(lVar8 + 0x68);
                                pcVar18 = *(code **)(lVar8 + 0x70);
                                *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar8 + 0x70) = 0;
                                *plVar15 = lVar17;
                                if (lVar17 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                                }
                                uVar21 = 0x4e;
                                goto LAB_23e10f622;
                              }
                              *plVar15 = lVar17;
                              if (lVar17 == 0) {
                                (**(code **)(plVar15[1] + 0x30))(plVar15);
                              }
                              if (iVar5 == 1) {
                                plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
                                if (plVar6 != (longlong *)0x0) {
                                  plVar15 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eea9968);
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  lVar17 = _DAT_23eea9970;
                                  if (plVar15 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar2 + 5) = 0x4f;
                                    plVar6 = (longlong *)
                                             FUN_23e9186b0(lVar8,plVar15,lVar17 + 0x18,
                                                           _DAT_23eea9978);
                                    *plVar15 = *plVar15 + -1;
                                    if (*plVar15 == 0) {
                                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                                    }
                                    if (plVar6 != (longlong *)0x0) {
                                      *plVar6 = *plVar6 + -1;
                                      if (*plVar6 == 0) {
                                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                                      }
                                      goto LAB_23e10f4a2;
                                    }
                                  }
                                }
                                uVar20 = *(undefined8 *)(lVar8 + 0x60);
                                uVar22 = *(undefined8 *)(lVar8 + 0x68);
                                pcVar18 = *(code **)(lVar8 + 0x70);
                                *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar8 + 0x70) = 0;
                                uVar21 = 0x4f;
                              }
                              else {
LAB_23e10f4a2:
                                lVar17 = _DAT_23eea9980;
                                *(undefined4 *)(plVar2 + 5) = 0x51;
                                plVar6 = (longlong *)
                                         FUN_23e915840(lVar8,plVar1,DAT_23eea98f8,
                                                       *(undefined8 *)(lVar17 + 0x18));
                                if (plVar6 != (longlong *)0x0) {
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  lVar17 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 8);
                                  plVar6 = *(longlong **)(lVar17 + 0x28);
                                  plVar2 = (longlong *)plVar6[2];
                                  *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8) =
                                       *(undefined8 *)(lVar17 + 0x30);
                                  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                                  if (plVar2 != (longlong *)0x0) {
                                    plVar6[2] = 0;
                                    *plVar2 = *plVar2 + -1;
                                    if (*plVar2 == 0) {
                                      (**(code **)(plVar2[1] + 0x30))();
                                    }
                                  }
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  plVar6[0xf] = 0;
                                  pcVar18 = _Py_NoneStruct_exref;
                                  *(longlong *)_Py_NoneStruct_exref =
                                       *(longlong *)_Py_NoneStruct_exref + 1;
LAB_23e10f5a6:
                                  *plVar1 = *plVar1 + -1;
                                  if (*plVar1 != 0) {
                                    return pcVar18;
                                  }
                                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                                  return pcVar18;
                                }
                                uVar20 = *(undefined8 *)(lVar8 + 0x60);
                                uVar22 = *(undefined8 *)(lVar8 + 0x68);
                                pcVar18 = *(code **)(lVar8 + 0x70);
                                *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar8 + 0x70) = 0;
                                uVar21 = 0x51;
                              }
                              goto LAB_23e10f622;
                            }
                          }
                        }
                        uVar20 = *(undefined8 *)(lVar8 + 0x60);
                        uVar22 = *(undefined8 *)(lVar8 + 0x68);
                        pcVar18 = *(code **)(lVar8 + 0x70);
                        *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(lVar8 + 0x70) = 0;
                        uVar21 = 0x4e;
                        goto LAB_23e10f622;
                      }
                      plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
                      if (plVar6 != (longlong *)0x0) {
                        *(undefined4 *)(plVar2 + 5) = 0x4a;
                        plVar15 = (longlong *)FUN_23e91bfe0(lVar8,plVar6,_DAT_23eea9948);
                        *plVar6 = *plVar6 + -1;
                        if (*plVar6 == 0) {
                          (**(code **)(plVar6[1] + 0x30))(plVar6);
                        }
                        if (plVar15 != (longlong *)0x0) {
                          iVar5 = FUN_23a35f020(plVar15);
                          lVar17 = *plVar15 + -1;
                          if (iVar5 == -1) {
                            uVar20 = *(undefined8 *)(lVar8 + 0x60);
                            uVar22 = *(undefined8 *)(lVar8 + 0x68);
                            pcVar18 = *(code **)(lVar8 + 0x70);
                            *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(lVar8 + 0x70) = 0;
                            *plVar15 = lVar17;
                            if (lVar17 == 0) {
                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                            }
                            uVar21 = 0x4a;
                            goto LAB_23e10f622;
                          }
                          *plVar15 = lVar17;
                          if (lVar17 == 0) {
                            (**(code **)(plVar15[1] + 0x30))(plVar15);
                          }
                          if (iVar5 != 1) goto LAB_23e10f450;
                          plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
                          if (plVar15 != (longlong *)0x0) {
                            plVar6 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eea9950);
                            *plVar15 = *plVar15 + -1;
                            if (*plVar15 == 0) {
                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                            }
                            if (plVar6 != (longlong *)0x0) {
                              plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
                              if (plVar15 != (longlong *)0x0) {
                                plVar9 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eea9958);
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                                }
                                if (plVar9 != (longlong *)0x0) {
                                  *(undefined4 *)(plVar2 + 5) = 0x4b;
                                  plVar15 = (longlong *)FUN_23e914090(lVar8,plVar6,plVar9);
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  if (plVar15 != (longlong *)0x0) {
                                    *plVar15 = *plVar15 + -1;
                                    if (*plVar15 == 0) {
                                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                                    }
                                    goto LAB_23e10f450;
                                  }
                                  goto LAB_23e10fc48;
                                }
                              }
                              uVar20 = *(undefined8 *)(lVar8 + 0x60);
                              uVar22 = *(undefined8 *)(lVar8 + 0x68);
                              uVar23 = 0x4b;
                              uVar21 = 0x4b;
                              pcVar18 = *(code **)(lVar8 + 0x70);
                              *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(lVar8 + 0x70) = 0;
                              *plVar6 = *plVar6 + -1;
                              lVar17 = *plVar6;
                              goto joined_r0x00023e10fbb9;
                            }
                          }
LAB_23e10fc48:
                          uVar20 = *(undefined8 *)(lVar8 + 0x60);
                          uVar22 = *(undefined8 *)(lVar8 + 0x68);
                          uVar21 = 0x4b;
                          pcVar18 = *(code **)(lVar8 + 0x70);
                          *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(lVar8 + 0x70) = 0;
                          goto LAB_23e10f622;
                        }
                      }
LAB_23e10f908:
                      uVar20 = *(undefined8 *)(lVar8 + 0x60);
                      uVar22 = *(undefined8 *)(lVar8 + 0x68);
                      uVar21 = 0x4a;
                      pcVar18 = *(code **)(lVar8 + 0x70);
                      *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(lVar8 + 0x70) = 0;
                    }
                    goto LAB_23e10f622;
                  }
                }
                pcVar18 = *(code **)(lVar8 + 0x70);
                *(undefined8 *)(lVar8 + 0x70) = 0;
                uVar21 = 0x44;
                uVar20 = *(undefined8 *)(lVar8 + 0x60);
                uVar22 = *(undefined8 *)(lVar8 + 0x68);
                *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
LAB_23e10f622:
                pcVar12 = DAT_23ed6a4f8;
                if (pcVar18 == (code *)0x0) {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar18 = *(code **)DAT_23ed6a4f8;
                    *(longlong *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar18;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    pcVar14 = pcVar12;
                  }
                  pcVar18 = _PyRuntime_exref;
                  *(longlong *)(pcVar14 + 0x10) = 0;
                  *(longlong **)(pcVar14 + 0x18) = plVar2;
                  *plVar2 = *plVar2 + 1;
                  lVar17 = *(longlong *)(pcVar18 + 0x1f8);
                  *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
                  lVar17 = *(longlong *)(lVar17 + 0x10);
                  *(undefined4 *)(pcVar14 + 0x24) = uVar21;
                  lVar17 = *(longlong *)(lVar17 + 0x2e8);
                  lVar3 = *(longlong *)(pcVar14 + -8);
                  puVar19 = *(undefined8 **)(lVar17 + 8);
                  *puVar19 = pcVar14 + -0x10;
                  *(longlong *)(pcVar14 + -0x10) = lVar17;
                  *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar19;
                  *(code **)(lVar17 + 8) = pcVar14 + -0x10;
                }
                else {
                  pcVar14 = pcVar18;
                  if (*(longlong **)(pcVar18 + 0x18) != plVar2) {
                    if (DAT_23ed6a4f8 == (code *)0x0) {
                      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                    }
                    else {
                      pcVar14 = *(code **)DAT_23ed6a4f8;
                      *(longlong *)DAT_23ed6a4f8 = 1;
                      DAT_23ed6a4f8 = pcVar14;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      pcVar14 = pcVar12;
                    }
                    pcVar12 = _PyRuntime_exref;
                    *(longlong **)(pcVar14 + 0x18) = plVar2;
                    *plVar2 = *plVar2 + 1;
                    lVar17 = *(longlong *)(pcVar12 + 0x1f8);
                    *(undefined4 *)(pcVar14 + 0x24) = uVar21;
                    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
                    lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
                    lVar3 = *(longlong *)(pcVar14 + -8);
                    puVar19 = *(undefined8 **)(lVar17 + 8);
                    *puVar19 = pcVar14 + -0x10;
                    *(longlong *)(pcVar14 + -0x10) = lVar17;
                    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar19
                    ;
                    lVar3 = *(longlong *)pcVar18;
                    *(code **)(lVar17 + 8) = pcVar14 + -0x10;
                    *(code **)(pcVar14 + 0x10) = pcVar18;
                    if (lVar3 == 0) {
                      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
                    }
                  }
                }
                FUN_23e8bba40(plVar2,&DAT_23ec5a08d,plVar1);
                if (_DAT_23eeab430 == plVar2) {
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  _DAT_23eeab430 = (longlong *)0x0;
                }
                lVar17 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 8);
                plVar6 = *(longlong **)(lVar17 + 0x28);
                plVar2 = (longlong *)plVar6[2];
                *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
                *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                if (plVar2 != (longlong *)0x0) {
                  plVar6[2] = 0;
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))();
                  }
                }
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                }
                plVar6[0xf] = 0;
                *plVar1 = *plVar1 + -1;
                if (*plVar1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                FUN_23a33aa70(lVar8,uVar20,uVar22,pcVar14);
                return (code *)0x0;
              }
              *plVar13 = *plVar13 + 1;
              DAT_23ed6a4c0 = plVar13;
            }
            uStack_a0 = uVar20;
            plStack_a8 = plVar6;
            lVar8 = FUN_23e94ed00(param_1,plVar13,&plStack_a8);
            if (lVar8 == 0) {
              plStack_c0 = *(longlong **)(param_1 + 0x60);
              pcVar12 = *(code **)(param_1 + 0x68);
              pcVar18 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              lVar8 = *plVar10;
              iStack_b0 = 0x3f;
              *plVar10 = lVar8 + -1;
              if (lVar8 + -1 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
                iStack_b0 = 0x3f;
              }
            }
            else {
              plVar10[4] = lVar8;
              plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar9 == (longlong *)0x0) {
                plStack_c0 = *(longlong **)(param_1 + 0x60);
                pcVar12 = *(code **)(param_1 + 0x68);
                pcVar18 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                iStack_b0 = 0x3f;
              }
              else {
                *(undefined4 *)(plVar2 + 5) = 0x3f;
                plVar10 = (longlong *)FUN_23e914090(param_1,plVar7,plVar9);
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  plVar6 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plVar15;
                  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
                    (**(code **)(plVar6[1] + 0x30))();
                  }
                  goto LAB_23e10e233;
                }
                plStack_c0 = *(longlong **)(param_1 + 0x60);
                pcVar12 = *(code **)(param_1 + 0x68);
                iStack_b0 = 0x3f;
                pcVar18 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
              }
            }
          }
        }
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
          pcVar16 = *(code **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar15;
        }
        else {
          pcVar16 = *(code **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar15;
        }
        if (pcVar16 == (code *)0x0) {
          if (pcVar18 != (code *)0x0) {
            pcVar11 = pcVar18;
            if (plVar2 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23e10e930;
            goto LAB_23e10e898;
          }
        }
        else {
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
          if (*(longlong *)pcVar16 == 0) goto LAB_23e10ed21;
          pcVar16 = pcVar12;
          if (pcVar18 != (code *)0x0) goto LAB_23e10ec8c;
        }
      }
      goto LAB_23e10eb83;
    }
    *(undefined4 *)(plVar2 + 5) = 0x34;
    plVar6 = (longlong *)FUN_23e915840(param_1,plVar1,uVar20,*(undefined8 *)(lVar8 + 0x18));
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      pcVar18 = _Py_FalseStruct_exref;
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e10e233:
      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar6 = *(longlong **)(lVar8 + 0x28);
      plVar2 = (longlong *)plVar6[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
      *(undefined4 *)(plVar6 + 8) = 0xffffffff;
      if (plVar2 != (longlong *)0x0) {
        plVar6[2] = 0;
        *plVar2 = *plVar2 + -1;
        if (*plVar2 == 0) {
          (**(code **)(plVar2[1] + 0x30))();
        }
      }
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      plVar6[0xf] = 0;
LAB_23e10e281:
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return pcVar18;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return pcVar18;
    }
    plStack_c0 = *(longlong **)(param_1 + 0x60);
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar14 = _PyRuntime_exref;
    if (pcVar18 == (code *)0x0) {
      iStack_b0 = 0x34;
      goto LAB_23e10eb83;
    }
    pcVar11 = pcVar18;
    if (*(longlong **)(pcVar18 + 0x18) == plVar2) goto LAB_23e10e930;
    iStack_b0 = 0x34;
  }
LAB_23e10e898:
  pcVar11 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar11 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar16 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar16;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar11 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  *(int *)(pcVar11 + 0x24) = iStack_b0;
  lVar8 = *(longlong *)(pcVar14 + 0x1f8);
  *(undefined4 *)(pcVar11 + 0x20) = 0xffffffff;
  lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
  lVar17 = *(longlong *)(pcVar11 + -8);
  puVar19 = *(undefined8 **)(lVar8 + 8);
  *puVar19 = pcVar11 + -0x10;
  *(longlong *)(pcVar11 + -0x10) = lVar8;
  *(ulonglong *)(pcVar11 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar19;
  lVar17 = *(longlong *)pcVar18;
  *(code **)(lVar8 + 8) = pcVar11 + -0x10;
  *(code **)(pcVar11 + 0x10) = pcVar18;
  if (lVar17 == 0) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
LAB_23e10e930:
  FUN_23e8bba40(plVar2,&DAT_23ec5a08f,plVar1,0);
  if (_DAT_23eeab448 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeab448 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar8 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  plVar2 = (longlong *)plVar6[2];
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_c0,pcVar12,pcVar11);
  return (code *)0x0;
}
